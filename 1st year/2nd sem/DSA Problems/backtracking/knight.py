import numpy as np
import random as rand

from backtracking_chess_api import run_chess_backtracking

N = 8
dx, dy = [2, 1, -1, -2, -2, -1, 1, 2], [1, 2, 2, 1, -1, -2, -2, -1]

knight_chessboard = np.full((N, N), 0)
start_x, start_y = rand.randint(0, N - 1), rand.randint(0, N - 1)

# run_chess_backtracking(knight_chessboard, start_x, start_y, 1, dx, dy)
