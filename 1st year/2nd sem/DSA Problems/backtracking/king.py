import numpy as np
import random as rand

from backtracking_chess_api import run_chess_backtracking_util, N, print_solution


def run_chess_backtracking_for_king(chessboard):
    dx, dy = [-1, -1, -1, 0, 1, 1, 1, 0], [-1, 0, 1, 1, 1, 0, -1, -1]
    start_x, start_y = rand.randint(0, N - 1), rand.randint(0, N - 1)
    # start_x, start_y = 0, 0

    if not run_chess_backtracking_util(chessboard, start_x, start_y, 1, dx, dy, "king"):
        print("There is no solution")
        return False

    print("Final solution for knight:")
    print_solution(chessboard, start_x, start_y)
    return True


knight_chessboard = np.full((N, N), 0)
run_chess_backtracking_for_king(knight_chessboard)
