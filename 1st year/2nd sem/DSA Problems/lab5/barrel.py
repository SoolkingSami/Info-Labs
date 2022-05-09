# DP[i][l] = the maximum profit achievable by picking
# from the first ith pieces up to the l current max length

# DP[i][l] = max(DP[i-1][l], DP[i-1][l-length[i]] + profit[i]) if length[i] <= l else DP[i-1][l]

class Piece:
    def __init__(self, length, profit):
        self.length = length
        self.profit = profit

    def __str__(self):
        return f"{self.length} cm: {self.profit}$"


def solve(pieces, length_max):
    DP = [[0 for _ in range(length_max + 1)] for _ in range(len(pieces) + 1)]
    for i in range(1, len(pieces) + 1):
        for cmax_len in range(1, length_max + 1):
            # the item cannot be included as its length is greater than the current max length
            if cmax_len < pieces[i - 1].length:
                DP[i][cmax_len] = DP[i - 1][cmax_len]
            # the item can be included, so we'll pick the max profit by including/not including it
            else:
                DP[i][cmax_len] = max(DP[i - 1][cmax_len],
                                      DP[i - 1][cmax_len - pieces[i - 1].length] + pieces[i - 1].profit)

    max_price = DP[len(pieces)][length_max]
    return max_price, compute_solution(DP, pieces, length_max)


def compute_solution(DP, pieces, length_max):
    res = []
    i = len(pieces)
    while i > 0:
        # the profit is the same as the previous one, so the ith piece is not included
        if DP[i][length_max] == DP[i - 1][length_max]:
            i -= 1
        # the profit is different, so the ith piece is included
        else:
            res.append(pieces[i - 1])
            # the max length is decreased by the length of the ith piece
            length_max -= pieces[i - 1].length
            i -= 1
    return res


pieces_arr = [Piece(1, 1), Piece(2, 5), Piece(3, 8), Piece(4, 9), Piece(5, 10), Piece(6, 17), Piece(7, 17),
              Piece(8, 20)]
len_max = 8
max_profit, solution = solve(pieces_arr, len_max)
print(f"The maximum profit is {max_profit}$ for the following solution:")
for piece in solution:
    print(piece)
