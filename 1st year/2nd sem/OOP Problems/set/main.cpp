#include <iostream>

using namespace std;

class Set {
private:
    int *arr;
    int size;

public:
    Set(int size=0, int *arr=nullptr);
    ~Set();
    void print() const;
    static Set* unionSet(const Set& set1, const Set& set2);
    static Set *intersectionSet(const Set& set1, const Set& set2);
};

Set::Set(int size, int *arr) {
    this->size = size;
    this->arr = arr;
}

Set::~Set() {
    delete[] arr;
}

void Set::print() const {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

Set* Set::unionSet(const Set& set1, const Set& set2) {
    cout << "Union: " << endl;
    int *newArr = new int[set1.size + set2.size];
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < set1.size && j < set2.size) {
        if (set1.arr[i] < set2.arr[j]) {
            newArr[k++] = set1.arr[i];
            i++;
        } else if (set1.arr[i] > set2.arr[j]) {
            newArr[k++] = set2.arr[j];
            j++;
        } else {
            newArr[k++] = set1.arr[i];
            i++;
            j++;
        }
    }
    while (i < set1.size) {
        newArr[k++] = set1.arr[i];
        i++;
    }
    while (j < set2.size) {
        newArr[k++] = set2.arr[j];
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

Set* Set::intersectionSet(const Set& set1, const Set& set2) {
    cout << "Intersection: " << endl;
    int *newArr = new int[set1.size + set2.size];
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < set1.size && j < set2.size) {
        if (set1.arr[i] < set2.arr[j]) {
            i++;
        } else if (set1.arr[i] > set2.arr[j]) {
            j++;
        } else {
            newArr[k++] = set1.arr[i];
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

    Set *set3 = Set::unionSet(set1, set2);
    set3->print();

    Set *set4 = Set::intersectionSet(set1, set2);
    set4->print();

    return 0;
}
