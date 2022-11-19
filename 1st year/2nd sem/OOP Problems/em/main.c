#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N_MAX 1010

int count_str(char *str, char *substr) {
    int count = 0;
    char *p = str;
    p = strstr(p, substr);
    while (p != NULL) {
        count++;
        p++;
        p = strstr(p, substr);
    }
    return count;
}


int main() {
    FILE *fin = fopen("em2.in", "r"), *fout = fopen("em2.out", "w");
    int n = 0;

//    while (fgets(s[n], N_MAX, fin) != NULL) {
//        s[n][strlen(s[n]) - 1] = '\0';
//        n++;
//    }
//    --n;

    // read first line
    char *str = (char *) malloc(N_MAX * sizeof(char));
    fgets(str, N_MAX, fin);
    str[strlen(str) - 1] = '\0';
    n++;

    // count the number of lines
    while (fgets(str, N_MAX, fin) != NULL) {
        str[strlen(str) - 1] = '\0';
        n++;
    }

    // allocate memory for the array of strings
    char **s = (char **) malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        s[i] = (char *) malloc(strlen(str) * sizeof(char));
    }

    // read the strings
    rewind(fin);
    for (int i = 0; i < n; i++) {
        fgets(s[i], N_MAX, fin);
        s[i][strlen(s[i]) - 1] = '\0';
    }
    free(str);
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
