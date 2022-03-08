#include <iostream>

#define DIM 50

using namespace std;

struct Student {
    char name[DIM], faculty[DIM];
    float grade;

    void readStudent();

    void printStudent() const;
};

void Student::readStudent() {
    cin.ignore();
    cin.sync();

    cout << "Name:\n";
    cin.getline(name, DIM);
    cout << "Faculty:\n";
    cin.getline(faculty, DIM);
    cout << "Grade:\n";
    cin >> grade;
}

void Student::printStudent() const {
    cout << "Name: " << name << endl;
    cout << "Faculty: " << faculty << endl;
    cout << "Grade: " << grade << endl;
    cout << endl;
}

typedef Student StudentArray[DIM];

void readStudents(StudentArray &students, const int& n) {
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": " << endl;
        students[i].readStudent();
    }
}

void printStudents(const StudentArray &students, const int& n) {
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": " << endl;
        students[i].printStudent();
    }
}

int sortByName(const Student& s1, const Student& s2) {
    return strcmp(s1.name, s2.name);
}

int sortByGrade(const Student& s1, const Student& s2) {
    if (s1.grade == s2.grade) {
        return sortByName(s1, s2);
    } else {
        return s2.grade - s1.grade;
    }
}

namespace local {
    template<typename T>
    void swap(T &a, T &b) {
        T temp = a;
        a = b;
        b = temp;
    }
}

typedef int (*SortFunction)(const Student&, const Student&);

void sortStudents(StudentArray &students, const int& n, SortFunction sortFunction) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sortFunction(students[i], students[j]) > 0) {
                local::swap(students[i], students[j]);
            }
        }
    }
}

int main() {
    StudentArray students;
    int n;
    cout << "Number of students:" << endl;
    cin >> n;

    readStudents(students, n);
    sortStudents(students, n, sortByGrade);
    printStudents(students, n);

    return 0;
}