def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)


def binomial_coefficient(n, k):
    return factorial(n) // (factorial(k) * factorial(n - k))


def print_pascal_triangle(n):
    for i in range(n):
        for j in range(i + 1):
            print(binomial_coefficient(i, j), end=' ')
        print()


def print_pascal_triangle_dp(n):
    dp = [[0 for _ in range(i + 1)] for i in range(n)]
    for i in range(n):
        for j in range(i + 1):
            if j == 0 or j == i:
                dp[i][j] = 1
            else:
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
        print(dp[i])


# print_pascal_triangle(6)
print_pascal_triangle_dp(5)
