#include <stdio.h>
#include <memory.h>

// N can have maximum 9 digits and hence the maximum sum of digits is 81
long long dp[9][81];

long long solve_dp(int i, int curr_sum, int limit_sum, int len) {
    if (i == len) {
        return curr_sum == limit_sum;
    }

    if (dp[i][curr_sum] != -1) {
        return dp[i][curr_sum];
    }

    long long ans = 0;
    for (int curr_digit = 0; curr_digit <= 9; curr_digit++) {
        int new_curr_sum = curr_sum + curr_digit;
        ans += solve_dp(i + 1, new_curr_sum, limit_sum, len);
    }

    dp[i][curr_sum] = ans;
    return ans;
}

int main() {
    FILE *fin = fopen("jetoane.in", "r"), *fout = fopen("jetoane.out", "w");

    int s, a;
    fscanf(fin, "%d %d", &s, &a);
    memset(dp, -1, sizeof(dp));

    // dp[i][s] = number of distinct values less than N (in our case N = 10^a) with sum of digits = s and i digits

    // Base case
    // s == given sum and i == number of digits of N, then there is only one number else 0

    // Recursive case
    // for filling the (i+1)th digit, we treat every digit from 0 to 9 in the following way:
    // we add the digit to the sum of digits of the number and then we call the recursive function
    // for the next index and the new sum of digits

    fprintf(fout, "%lld", solve_dp(0, 0, s, a));

    fclose(fin);
    fclose(fout);
    return 0;
}
