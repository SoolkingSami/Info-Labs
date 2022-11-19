#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
#include <numeric>
#include <algorithm>

using namespace std;

bool is_eulerian(const int& no_vertices, const vector<int>& in_degree, const vector<int>& out_degree) {
    // declare numeric range from 0 to no_vertices
    vector<int> range(no_vertices);
    iota(range.begin(), range.end(), 0);

    auto check_equal_degree = [=](int i) -> bool {
        return in_degree[i] == out_degree[i];
    };
    int64_t count_equal_degree = count_if(range.begin(), range.end(), check_equal_degree);
    auto check_eulerian_out_degree = [=](int i) -> bool {
        return out_degree[i] - in_degree[i] == 1;
    };
    int64_t count_eulerian_out_degree = count_if(range.begin(), range.end(), check_eulerian_out_degree);
    auto check_eulerian_in_degree = [=](int i) -> bool {
        return in_degree[i] - out_degree[i] == 1;
    };
    int64_t count_eulerian_in_degree = count_if(range.begin(), range.end(), check_eulerian_in_degree);

    // the graph has an eulerian path iff:
    // 1. all vertices have equal in and out degree
    // 2. exactly one vertex has out degree - in degree = 1
    // 3. exactly one vertex has in degree - out degree = 1
    // 4. all other vertices have equal in and out degree
    return (count_equal_degree == no_vertices) ||
           (count_eulerian_out_degree == 1 && count_eulerian_in_degree == 1 && count_equal_degree == no_vertices - 2);
}

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }

        vector<vector<int>> adj(n);
        vector<int> in_degree(n, 0), out_degree(n, 0);
        for (int i = 0, u, v; i < m; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            ++in_degree[v];
            ++out_degree[u];
        }

        if (!is_eulerian(n, in_degree, out_degree)) {
            cout << "Impossible" << endl;
            continue;
        }

        // find the start vertex
        int start = -1;
        for (int i = 0; i < n; ++i) {
            if (out_degree[i] - in_degree[i] == 1) {
                start = i;
                break;
            }
        }
        if (start == -1) {
            for (int i = 0; i < n; ++i) {
                if (out_degree[i] > 0) {
                    start = i;
                    break;
                }
            }
        }

        // find the eulerian path using the Hierholzer's algorithm
        vector<int> path;
        stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int u = s.top();
            if (out_degree[u] == 0) {
                path.push_back(u);
                s.pop();
            } else {
                int v = adj[u].back();
                adj[u].pop_back();
                --out_degree[u];
                s.push(v);
            }
        }

        // print the path
        copy_n(path.rbegin(), path.size(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}
