import numpy as np
import random as rand

from backtracking_chess_api import run_chess_backtracking_util, N, print_solution


def run_chess_backtracking_for_knight(chessboard):
    dx, dy = [2, 1, -1, -2, -2, -1, 1, 2], [1, 2, 2, 1, -1, -2, -2, -1]
    start_x, start_y = rand.randint(1, N - 1), rand.randint(1, N - 1)
    # start_x, start_y = 0, 0

    if not run_chess_backtracking_util(chessboard, start_x, start_y, 1, dx, dy, "knight"):
        print("There is no solution")
        return False

    print("Final solution for knight:")
    print_solution(chessboard, start_x, start_y)
    return True


knight_chessboard = np.full((N + 2, N + 2), 0)

# bord the matrix
for i in range(0, N + 2):
    knight_chessboard[i][0] = knight_chessboard[i][1] =

run_chess_backtracking_for_knight(knight_chessboard)
