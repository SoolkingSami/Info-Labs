#include <iostream>
#include <vector>
#include <map>

using namespace std;

void print_vector(const vector<int>& v) {
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements:\n";
    cin >> n;

    vector<int> v1(n), v2(n);
    cout << "Enter elements of vector 1:\n";
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }

    cout << "Enter elements of vector 2:\n";
    for (int i = 0; i < n; i++) {
        cin >> v2[i];
    }

    map<int, bool> m1, m2;
    int cut;
    cout << "Enter cut:\n";
    cin >> cut;

    for (int i = 0; i < cut; i++) {
        m1[v1[i]] = true;
    }
    for (int i = 0; i < cut; i++) {
        m2[v2[i]] = true;
    }

    cout << "Elements of vector 1:\n";
    print_vector(v1);

    cout << "Elements of vector 2:\n";
    print_vector(v2);

    /// move from v2 to v1
    vector<int> temp(v1);
    int count = cut;
    for (int i = cut; i < n && count != n; i++) {
        if (!m1[v2[i]]) {
            v1[count++] = v2[i];
            m1[v2[i]] = true;
        }
    }
    for (int i = 0; i < cut && count != n; i++) {
        if (!m1[v2[i]]) {
            v1[count++] = v2[i];
            m1[v2[i]] = true;
        }
    }

    /// move from v1 to v2
    count = cut;
    for (int i = cut; i < n && count != n; i++) {
        if (!m2[temp[i]]) {
            v2[count++] = temp[i];
            m2[temp[i]] = true;
        }
    }
    for (int i = 0; i < cut && count != n; i++) {
        if (!m2[temp[i]]) {
            v2[count++] = temp[i];
            m2[temp[i]] = true;
        }
    }

    cout << "Elements of vector 1:\n";
    print_vector(v1);

    cout << "Elements of vector 2:\n";
    print_vector(v2);

    v1.clear(), v2.clear(), temp.clear();
    m1.clear(), m2.clear();
    return 0;
}
