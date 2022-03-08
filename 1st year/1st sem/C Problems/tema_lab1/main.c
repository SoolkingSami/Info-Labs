/*
 * @author Barbut-Dica Nicusor Dumitru Sami
 * @group 211 A
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

// set the k-th bit
void solve1() {
    int n;
    short k;

    printf("Enter the number:\n");
    scanf_s("%d", &n);
    printf("Enter the bit to be set:\n");
    scanf_s("%d", &k);

    //  n:              110011_0_1001
    //  k:              000000_1_0000
    //  n | (1 << k):   110011_1_1001
    int new_n = n | (1 << k);
    printf("%d with the %d-th bit set is: %d\n", new_n, k, n);
}

// solve linear equation
void solve2() {
    float a, b;

    printf("Enter the a coefficient:\n");
    scanf_s("%f", &a);
    printf("Enter the b coefficient:\n");
    scanf_s("%f", &b);

    printf("The equation is: %.f*X %c %.f = 0\n", a, b > 0 ? '+' : '-', fabsf(b));

    if (a) {
        float x = -b / a;
        printf("The solution is:\nx = %.2f\n", x);
    } else {
        printf("The given equation cannot be solved!\n");
    }
}

// solve quadratic equation
void solve3() {
    float a, b, c;

    printf("Enter the a coefficient:\n");
    scanf_s("%f", &a);
    printf("Enter the b coefficient:\n");
    scanf_s("%f", &b);
    printf("Enter the c coefficient:\n");
    scanf_s("%f", &c);

    printf("The equation is: %.f*(X^2) %c %.f*X %c %.f = 0\n",
           a, b > 0 ? '+' : '-', fabsf(b), c > 0 ? '+' : '-', fabsf(c));

    if (!a && !b) {
        printf("The given equation cannot be solved!\n");
    } else if (!a && b) {
        float x = -c / b;
        printf("The solution is:\nx = %.2f\n", x);
    } else {
        float delta = powf(b, 2) - 4 * a * c;
        if (!delta) {
            float x12 = -b / (2 * a);
            printf("There is only one solution:\nx12 = %.2f\n", x12);
        } else if (delta < 0) {
            delta = fabsf(delta);
            struct _complex r = {.x = -b / (2 * a), .y = sqrtf(delta) / (2 * a)};
            printf("There are two complex solutions:\n");
            printf("x1 = %.2f - i*%.2f\nx2 = %.2f + i*%.2f\n", r.x, r.y, r.x, r.y);
        } else {
            float x1 = (-b - sqrtf(delta)) / (2 * a),
                  x2 = (-b + sqrtf(delta)) / (2 * a);
            printf("There are two real solutions:\nx1 = %.2f\nx2 = %.2f\n", x1, x2);
        }
    }
}

// compute the sum and product of the natural
// numbers less than or equal to n from 5 to 5
void solve4() {
    int n;
    long long sum = 0, prod = 1;

    printf("Enter the number:\n");
    scanf_s("%d", &n);

    for (int i = 1; i <= n; i += 5) {
        sum += i;
        prod *= i;
    }

    printf("The sum of the numbers less than n from 5 to 5 is: %lld\n", sum);
    printf("The product of the numbers less than n from 5 to 5 is: %lld\n", prod);
}

// compute the number of set bits using
// arithmetic and bitwise operators respectively
void solve5() {
    int nr_bits1 = 0, nr_bits2 = 0, n;

    printf("Enter the number:\n");
    scanf_s("%d", &n);

    // bitwise
    int aux = n;
    while (n) {
        nr_bits1 += n & 1;
        n >>= 1;
    }

    // arithmetic
    n = aux;
    while (n) {
        nr_bits2 += n % 2;
        n /= 2;
    }

    printf("The number of set bits in %d is: %d\n", aux, nr_bits1);
    assert(nr_bits1 == nr_bits2);
}

// compute the sum of n's digits and the product
// of those placed on even positions
void solve6() {
    int n, sum = 0, prod = 1, pos = 0;

    printf("Enter the number:\n");
    scanf_s("%d", &n);

    int aux = n;
    while (n) {
        sum += n % 10;
        if (!(pos & 1)) prod *= n % 10;

        ++pos;
        n /= 10;
    }

    printf("The sum of %d's digits is: %d\n", aux, sum);
    printf("The product of %d's digits placed on even positions is: %d\n", aux, prod);
}

short choice;

int main() {
    printf("Choose the exercise to solve:\n");
    scanf_s("%d", &choice);

    switch (choice) {
        case 1: {
            solve1();
            break;
        }
        case 2: {
            solve2();
            break;
        }
        case 3: {
            solve3();
            break;
        }
        case 4: {
            solve4();
            break;
        }
        case 5: {
            solve5();
            break;
        }
        case 6: {
            solve6();
            break;
        }
        default: {
            printf("Invalid exercise ID\n");
            exit(1);
        }
    }

    return 0;
}
