#include <iostream>
#include <random>
#include <vector>

using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 3);

namespace local {
    int rand() {
        return ::dis(::gen);
    }
}

namespace std {
    ostream& operator<<(ostream &os, const vector<int> &v) {
        for (const auto &e : v)
            os << e << ' ';
        return os;
    }
}

int main() {
    vector<vector<int>> state = {
        {2, 3, 5},
        {4, 0, 1},
        {8, 6, 7}
    };

    int rand_state = local::rand();
    string move;
    switch (rand_state) {
        int temp;
        case 0:
            temp = state[1][1];
            state[1][1] = state[0][1];
            state[0][1] = temp;
            move = "UP";
            break;
        case 1:
            temp = state[1][1];
            state[1][1] = state[2][1];
            state[2][1] = temp;
            move = "DOWN";
            break;
        case 2:
            temp = state[1][1];
            state[1][1] = state[1][0];
            state[1][0] = temp;
            move = "LEFT";
            break;
        case 3:
            temp = state[1][1];
            state[1][1] = state[1][2];
            state[1][2] = temp;
            move = "RIGHT";
            break;
        default:;
    }

    cout << move << endl;
    copy(state.begin(), state.end(), ostream_iterator<vector<int>>(cout, "\n"));

    state.clear();
    return 0;
}