#include <iostream>
#include <cstring>

using namespace std;

class Student {
private:
    char *name;
    char *address;
    int age;
    float grade;

public:
    Student(char *name="", char *address="", int age=0, float grade=0);
    Student(const Student &s);
    ~Student();
    void read();
    void print() const;

    char *getName() const {
        return name;
    }

    void setName(char *name) {
        Student::name = name;
    }

    char *getAddress() const {
        return address;
    }

    void setAddress(char *address) {
        Student::address = address;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Student::age = age;
    }

    float getGrade() const {
        return grade;
    }

    void setGrade(float grade) {
        Student::grade = grade;
    }

    Student& operator=(const Student &s);
};

Student::Student(char *name, char *address, int age, float grade) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
    this->age = age;
    this->grade = grade;
}

Student::~Student() {
    delete[] name;
    delete[] address;
}

void Student::read() {
    cout << "Enter name: ";
    cin.getline(name, 100);
    cout << "Enter address: ";
    cin.getline(address, 100);
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter grade: ";
    cin >> grade;
}

void Student::print() const {
    cout << "-----------------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Age: " << age << endl;
    cout << "Grade: " << grade << endl;
    cout << "-----------------------------" << endl;
}

Student::Student(const Student &s) {
    name = new char[strlen(s.name) + 1];
    strcpy(name, s.name);
    address = new char[strlen(s.address) + 1];
    strcpy(address, s.address);
    age = s.age;
    grade = s.grade;
}

Student &Student::operator=(const Student &s) {
    if (this != &s) {
        delete[] name;
        delete[] address;
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        address = new char[strlen(s.address) + 1];
        strcpy(address, s.address);
        age = s.age;
        grade = s.grade;
    }
    return *this;
}

typedef int (*compare_func)(const void *, const void *);

int compare_by_name(const void *a, const void *b) {
    Student *s1 = (Student *) a;
    Student *s2 = (Student *) b;
    return strcmp(s1->getName(), s2->getName());
}

int compare_by_age(const void *a, const void *b) {
    Student *s1 = (Student *) a;
    Student *s2 = (Student *) b;
    return s1->getAge() - s2->getAge();
}

int compare_by_grade(const void *a, const void *b) {
    Student *s1 = (Student *) a;
    Student *s2 = (Student *) b;
    return s1->getGrade() -s2->getGrade();
}

class StudentGroup {
private:
    Student *students;
    int size;

public:
    StudentGroup(int size=0, Student *students=nullptr);
    ~StudentGroup();

    void read();
    void print() const;

    void sort(compare_func compare);

    void addStudent(Student *student);
    void removeStudent(char *name);
    Student *findStudent(char *name);
};

StudentGroup::StudentGroup(int size, Student *students) {
    this->size = size;
    this->students = new Student[size];
    for (int i = 0; i < size; i++) {
        this->students[i] = students[i];
    }
}

StudentGroup::~StudentGroup() {
    delete[] students;
}

void StudentGroup::read() {
    cout << "Enter number of students: ";
    cin >> size;
    students = new Student[size];
    for (int i = 0; i < size; i++) {
        students[i].read();
    }
}

void StudentGroup::print() const {
    for (int i = 0; i < size; i++) {
        students[i].print();
    }
    cout << endl;
}

void StudentGroup::sort(compare_func compare) {
    cout << "Sorting..." << endl;
    qsort(students, size, sizeof(Student), compare);
}

void StudentGroup::addStudent(Student *student) {
    cout << "Add student: " << student->getName() << endl;
    Student *new_students = new Student[size + 1];
    for (int i = 0; i < size; i++) {
        new_students[i] = students[i];
    }
    new_students[size] = *student;
    delete[] students;
    students = new_students;
    size++;
}

void StudentGroup::removeStudent(char *name) {
    cout << "Removing student " << name << endl;
    Student *new_students = new Student[size - 1];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].getName(), name) != 0) {
            new_students[j] = students[i];
            j++;
        }
    }
    delete[] students;
    students = new_students;
    size--;
}

Student* StudentGroup::findStudent(char *name) {
    cout << "Searching student " << name << endl;
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].getName(), name) == 0) {
            return &students[i];
        }
    }
    return nullptr;
}

int main() {
    StudentGroup* group = new StudentGroup(3, new Student[3]{
        Student("Ivan", "Sofia", 20, 5.0),
        Student("Pesho", "Plovdiv", 21, 4.0),
        Student("Gosho", "Varna", 22, 3.0)
    });
//    group->read();
    group->print();

    group->sort(compare_by_name);
    group->print();

    group->sort(compare_by_age);
    group->print();

    group->sort(compare_by_grade);
    group->print();

    Student *student = group->findStudent("Ivan");
    if (student != nullptr) {
        student->print();
    }

    group->addStudent(new Student("Petru Alin", "Moscow", 25, 4.5));
    group->print();

    group->removeStudent("Ivan");
    group->print();

    return 0;
}
