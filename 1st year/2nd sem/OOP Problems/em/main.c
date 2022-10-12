#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N_MAX 1001

int count_str(char *str, char *substr) {
    int count = 0;
    char *p = str;
    while ((p = strstr(p, substr)) != NULL) {
        count++;
        p++;
    }
    return count;
}

char s[N_MAX][N_MAX];

int main() {
    FILE *fin = fopen("em.in", "r"), *fout = fopen("em.out", "w");
    int n = 0;

    while (fgets(s[n], N_MAX, fin) != NULL) {
        n++;
    }
    --n;

    // 1
    char *str_to_src = malloc(sizeof(char) * N_MAX);
    strcpy(str_to_src, s[n]);

    int cnt_str = 0;
    for (int i = 0; i < n; i++) {
        cnt_str += count_str(s[i], str_to_src);
    }

    fprintf(fout, "%d\n", cnt_str);
    free(str_to_src);

    // 2
    char *str_to_print = malloc(sizeof(char) * N_MAX * N_MAX);
    int cnt_char = 0;

    for (int i = 0; i < n; i++) {
        for (int k = i, j = i; k < n && j >= 0; k++, j--) {
            str_to_print[cnt_char++] = s[k][j];
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int k = i, j = n - 1; k >= 0 && j >= 0; k--, j--) {
            str_to_print[cnt_char++] = s[k][j];
        }
    }

    str_to_print[cnt_char] = '\0';
    fprintf(fout, "%s", str_to_print);
    free(str_to_print);

    fclose(fin);
    fclose(fout);
    return 0;
}
