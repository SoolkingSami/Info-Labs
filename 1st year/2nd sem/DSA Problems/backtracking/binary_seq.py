import numpy as np

N = 6
seq = np.full(N, 0)


def print_solution(sol, N):
    print('[', end="")
    for i in range(1, N):
        print(f'{sol[i]} ', end="")
    print('\b]')


def solve_binary_seq(step, sol):
    if step == N:
        print_solution(sol, N)

    else:
        for i in range(0, 2):
            sol[step] = i

            if sol[step - 1] + sol[step] != 2:
                solve_binary_seq(step + 1, sol)

            sol[step] = 0


# solve_binary_seq(0, seq)
