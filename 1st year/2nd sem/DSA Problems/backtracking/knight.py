import numpy as np
import random as rand
from termcolor import colored

N = 8
dx, dy = [2, 1, -1, -2, -2, -1, 1, 2], [1, 2, 2, 1, -1, -2, -2, -1]

knight_chessboard = np.full((N, N), 0)
start_x, start_y = rand.randint(0, N - 1), rand.randint(0, N - 1)


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


def knight_backtracking(chessboard, x, y, curr):
    knight_chessboard[x][y] = curr
    print(f"The knight is in ({x}, {y}) with the value {curr}:")
    print_solution(chessboard, x, y)

    for to_x, to_y in zip(dx, dy):
        new_x, new_y = x + to_x, y + to_y
        if is_safe(chessboard, new_x, new_y):
            knight_backtracking(chessboard, new_x, new_y, curr + 1)


knight_backtracking(knight_chessboard, start_x, start_y, 1)
