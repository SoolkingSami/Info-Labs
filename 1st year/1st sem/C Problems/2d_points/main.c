#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * struct life cycle functions:
 * - create instance
 * - read instance
 * - write instance
 * - delete instance
 */

typedef enum {
    Equilateral,
    Isosceles,
    Scalene,
    NotTriangle
} TriangleType;

typedef struct {
    int x, y;
} Point;

Point *newPoint() {
    Point *p = malloc(sizeof(Point));
    return p;
}

void readPoint(Point *p) {
    printf("\nEnter x:");
    scanf("%d", &p->x);
    printf("Enter y: ");
    scanf("%d", &p->y);
    printf("\n");
}

void printPoint(Point *p) {
    printf("(%d, %d)\n", p->x, p->y);
}

double distance(Point *p1, Point *p2) {
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

typedef struct {
    Point *p1, *p2, *p3;

    TriangleType type;
    double cachedA, cachedB, cachedC;
} Triangle;

Triangle* newTriangle() {
    Triangle *t = malloc(sizeof(Triangle));
    t->p1 = newPoint();
    t->p2 = newPoint();
    t->p3 = newPoint();
    return t;
}

TriangleType getTriangleType(Triangle *t) {
    if (t->cachedA + t->cachedB <= t->cachedC ||
        t->cachedA + t->cachedC <= t->cachedB ||
        t->cachedB + t->cachedC <= t->cachedA) {
        return NotTriangle;
    } else {
        if (t->cachedA == t->cachedB && t->cachedB == t->cachedC) {
            return Equilateral;
        } else if (t->cachedA == t->cachedB || t->cachedB == t->cachedC || t->cachedC == t->cachedA) {
            return Isosceles;
        } else {
            return Scalene;
        }
    }
}

void readTriangle(Triangle *t) {
    printf("Enter triangle points:\n");

    printf("Point 1: ");
    readPoint(t->p1);
    printf("Point 2: ");
    readPoint(t->p2);
    printf("Point 3: ");
    readPoint(t->p3);

    t->cachedA = distance(t->p1, t->p2);
    t->cachedB = distance(t->p2, t->p3);
    t->cachedC = distance(t->p3, t->p1);
    t->type = getTriangleType(t);
}

void printTriangle(Triangle *t) {
    printf("Triangle:\nA = %.2f, B = %.2f, C = %.2f\n", t->cachedA, t->cachedB, t->cachedC);
    printPoint(t->p1);
    printPoint(t->p2);
    printPoint(t->p3);
    printf("\nThe given triangle is %s\n", t->type == Equilateral
           ? "equilateral"
           : t->type == Isosceles
                ? "isosceles"
                : "scalene");
}

void freeTriangle(Triangle *t) {
    free(t->p1);
    free(t->p2);
    free(t->p3);
    free(t);
}

int main() {
    Triangle *t = newTriangle();
    readTriangle(t);
    printTriangle(t);
    freeTriangle(t);

    return 0;
}
