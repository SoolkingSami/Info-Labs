#include <stdio.h>

#define R_MAX 101
#define M_MAX 1001
#define MOD 9001

long long comb(int n, int k) {
    long long ret = 1;
    for (int i = 1; i <= k; i++) {
        ret *= n - i + 1;
        ret /= i;
        ret %= MOD;
    }
    return ret;
}

int rc[R_MAX], dp[R_MAX][M_MAX][R_MAX];

int main() {
    FILE *fin = fopen("carti.in", "r"), *fout = fopen("carti.out", "w");
    int n, m;

    fscanf(fin, "%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        fscanf(fin, "%d", &x);
        rc[x % 100]++;
    }

    // definition:
    // rc[i] = number of isbn codes with `isbn mod 100 = i` (residue class)
    // 0 <= i <= 99, 0 <= j <= m, 0 <= r <= 99
    // dp[i][j][r] = (number of combinations of j ints from rc[0..i-1] with sum congruent to r) mod 9001

    // base cases:
    // dp[0][0][0] = 1
    // dp[0][j][r] = 0 for j > 0 or r > 0

    // recurrence:
    // dp[i][j][r] = (Sum from p = 0 to min(j, rc[i]) of (rc[i] choose p) * dp[i-1][j-p][(r-p*i) mod 100]) mod 9001

    // explanation:
    // for each new residue class i, we can choose 0 to min(j, rc[i]) elements from it
    // to add to the previous number of combinations among residue classes 0 to i-1, with number of items equal to
    // the rest j-p and their sum congruent to r-p*i

    // time complexity: O((m * r_max) ^ 2)

    dp[0][0][0] = 1;

    // treat residue class 0 as a special case
    for (int j = 1; j <= m; j++) {
        dp[0][j][0] = comb(rc[0], j);
    }

    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j <= m; j++) {
            for (int r = 0; r <= 99; r++) {
                dp[i][j][r] = 0;

                for (int p = 0; p <= j && p <= rc[i]; p++) {
                    dp[i][j][r] += comb(rc[i], p) * dp[i-1][j-p][(r - p*i + 100) % 100];
                    dp[i][j][r] %= MOD;
                }
            }
        }
    }

    fprintf(fout, "%d", dp[100][m][0]);

    fclose(fin);
    fclose(fout);
    return 0;
}
