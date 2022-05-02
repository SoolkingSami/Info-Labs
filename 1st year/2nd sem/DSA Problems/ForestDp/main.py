import numpy as np

# read the forest matrix
with open('forest1.txt', 'rt') as f:
    n, m = list(map(int, f.readline().split()))
    forest = np.full((n, m), 0)
    for idx, line in enumerate(f.readlines()):
        forest[idx] = list(map(int, line.split()))

# for i in range(0, n):
#     for j in range(0, m):
#         print(forest[i][j], end=" ")
#     print()

# DP Recursion Algorithm:
#
# 1. DP[i][j] = the maximum number of acorns gathered by the squirrel
#    on the way from (0, 0) to (i, j)
# 2. DP[0][0] = Forest[0][0]
#    DP[i][0] = Forest[i][0] + DP[i - 1][0]
#    DP[0][j] = Forest[0][j] + DP[0][j - 1]
# 3. DP[i][j] = Forest[i][j] + max(DP[i - 1][j], DP[i][j - 1]), i = 1..n - 1, j = 1..m - 1
# 4. DP[n - 1][m - 1] - final solution

dp = np.full((n, m), 0)
dp[0][0] = forest[0][0]
for i in range(1, n):
    dp[i][0] = forest[i][0] + dp[i - 1][0]
for j in range(1, m):
    dp[0][j] = forest[0][j] + dp[0][j - 1]

for i in range(1, n):
    for j in range(1, m):
        dp[i][j] = forest[i][j] + max(dp[i - 1][j], dp[i][j - 1])

start = (0, 0)
end = (n - 1, m - 1)


def compute_dp_path(curr):
    if curr == start:
        print(curr)
    else:
        row, col = curr
        next_val = dp[row][col] - forest[row][col]
        if next_val == dp[row - 1][col]:
            compute_dp_path((row - 1, col))
        elif next_val == dp[row][col - 1]:
            compute_dp_path((row, col - 1))
        print(curr)


print(f'The maximum number of acorns gathered by the squirrel: {dp[n - 1][m - 1]}')
print('The path followed by the squirrel is:')
compute_dp_path(end)
