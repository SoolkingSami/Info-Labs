N = 4
dx, dy = [-1, 0, 1, 0], [0, 1, 0, -1]


def print_solution(sol):
    for i in sol:
        for j in i:
            print(f'{j:<5}', end="")
        print()
    print()


def is_safe(maze_local, x, y, sol):
    if 0 <= x < N and 0 <= y < N and maze_local[x][y] == 1 and sol[x][y] == 0:
        return True
    return False


def solve_maze(maze_local):
    sol = [[0 for _ in range(4)] for _ in range(4)]
    print(f"The initial maze:")
    print_solution(maze_local)

    if not solve_maze_util(maze_local, 0, 0, sol):
        print("There is no solution")
        return False

    print(f"Final solution from (0, 0) to ({N - 1}, {N - 1}):")
    print_solution(sol)
    return True


def solve_maze_util(maze_local, x, y, sol):
    print(f'We are currently in ({x}, {y}):')
    print_solution(sol)

    if x == N - 1 and y == N - 1:
        sol[x][y] = 1
        return True

    if is_safe(maze_local, x, y, sol):
        sol[x][y] = 1

        for to_x, to_y in zip(dx, dy):
            if solve_maze_util(maze_local, x + to_x, y + to_y, sol):
                return True

        sol[x][y] = 0
        return False


maze = [[1, 0, 0, 0], [1, 1, 0, 1], [0, 1, 0, 0], [1, 1, 1, 1]]
# with open("maze.txt", "rt") as f:
#     N = int(next(f))
#     start_x, start_y, end_x, end_y =
# solve_maze(maze)
