#include <stdio.h>
#include <stdlib.h>

#define DIM 50

typedef struct {
    char name[DIM], faculty[DIM];
    float grade;
} Student;

void read_student(Student* student) {
    printf("Name:\n");
    scanf("%s", student->name);
    printf("Faculty:\n");
    scanf("%s", student->faculty);
    printf("Grade:\n");
    scanf("%f", &student->grade);
}

void print_student(Student student) {
    printf("Name: %s\n", student.name);
    printf("Faculty: %s\n", student.faculty);
    printf("Grade: %.2f\n", student.grade);
    printf("\n");
}

void read_students(Student* students, int n) {
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        read_student(&students[i]);
    }
}

void print_students(Student* students, int n) {
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        print_student(students[i]);
    }
}

int main() {
    int n;
    printf("Number of students:\n");
    scanf("%d", &n);

    Student* students = (Student*) malloc(n * sizeof(Student));
    read_students(students, n);
    print_students(students, n);

    free(students);
    return 0;
}
