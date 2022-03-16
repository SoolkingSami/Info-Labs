#include <iostream>

using namespace std;

class Set {
private:
    int *arr;
    int size;

public:
    Set(int size, int *arr);
    ~Set();
    void print();
    Set* unionSet(const Set& set);
    Set *intersectionSet(const Set& set);
};

Set::Set(int size, int *arr) {
    this->size = size;
    this->arr = arr;
}

Set::~Set() {
    delete[] arr;
}

void Set::print() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

Set* Set::unionSet(const Set& set) {
    cout << "Union: " << endl;
    int *newArr = new int[size + set.size];
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < size && j < set.size) {
        if (arr[i] < set.arr[j]) {
            newArr[k++] = arr[i];
            i++;
        } else if (arr[i] > set.arr[j]) {
            newArr[k++] = set.arr[j];
            j++;
        } else {
            newArr[k++] = arr[i];
            i++;
            j++;
        }
    }
    while (i < size) {
        newArr[k++] = arr[i];
        i++;
    }
    while (j < set.size) {
        newArr[k++] = set.arr[j];
        j++;
    }
    int *temp = newArr;
    newArr = new int[k];
    for (int l = 0; l < k; l++) {
        newArr[l] = temp[l];
    }

    Set *newSet = new Set(k, newArr);
    return newSet;
}

Set* Set::intersectionSet(const Set& set) {
    cout << "Intersection: " << endl;
    int *newArr = new int[size + set.size];
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < size && j < set.size) {
        if (arr[i] < set.arr[j]) {
            i++;
        } else if (arr[i] > set.arr[j]) {
            j++;
        } else {
            newArr[k++] = arr[i];
            i++;
            j++;
        }
    }
    int *temp = newArr;
    newArr = new int[k];
    for (int l = 0; l < k; l++) {
        newArr[l] = temp[l];
    }

    Set *newSet = new Set(k, newArr);
    return newSet;
}

int main() {
    Set set1(5, new int[5]{1, 2, 3, 4, 5});
    Set set2(3, new int[3]{1, 2, 3});

    set1.print();
    set2.print();

    Set *set3 = set1.unionSet(set2);
    set3->print();

    Set *set4 = set1.intersectionSet(set2);
    set4->print();

    return 0;
}
