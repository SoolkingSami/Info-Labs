from termcolor import colored

N = 8


def print_solution(sol, x, y):
    for row, i in enumerate(sol):
        for col, j in enumerate(i):
            if (row, col) == (x, y):
                print(colored(f'{j:<5}', 'green'), end="")
            elif j != 0:
                print(colored(f'{j:<5}', 'red'), end="")
            else:
                print(f'{j:<5}', end="")
        print()
    print()


def is_safe(chessboard, x, y):
    return 0 <= x < N and 0 <= y < N and chessboard[x][y] == 0


def run_chess_backtracking_util(chessboard, x, y, curr, dx, dy, name):
    if curr == N * N + 1:
        return True

    if is_safe(chessboard, x, y):
        chessboard[x][y] = curr
        # print(f"The {name} is in ({x}, {y}) with the value {curr}:")
        # print_solution(chessboard, x, y)

        for to_x, to_y in zip(dx, dy):
            new_x, new_y = x + to_x, y + to_y
            if run_chess_backtracking_util(chessboard, new_x, new_y, curr + 1, dx, dy, name):
                return True

        chessboard[x][y] = 0
        return False
