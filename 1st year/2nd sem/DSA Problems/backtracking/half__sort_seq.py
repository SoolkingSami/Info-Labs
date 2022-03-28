import numpy as np

from binary_seq import print_solution

N = 8
mid = (N - 1) // 2
seq = np.full(N, N)
used = np.full(N, False)


def solve_half_sort_seq(step, sol):
    # solution
    if step == N:
        print_solution(sol, N)
    # left side related to mid - sort desc
    elif step <= mid:
        for i in range(1, sol[step - 1]):
            if not used[i]:
                sol[step] = i
                used[i] = True

                solve_half_sort_seq(step + 1, sol)

                used[i] = False
                sol[step] = 0
    # right side related to mid - sort asc
    elif step > mid:
        for i in range(sol[step - 1] + 1, N):
            if not used[i]:
                sol[step] = i
                used[i] = True

                solve_half_sort_seq(step + 1, sol)

                used[i] = False
                sol[step] = 0


solve_half_sort_seq(1, seq)
