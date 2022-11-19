#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    ifstream fin("dirty.in");
    ofstream fout("dirty.out");

    int n, m;
    fin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<bool> seen(n + 1, false);
    vector<int> low(n + 1, 0), disc(n + 1, 0), parent(n + 1, 0);
    vector<int> max_art_points(n + 1, 1);
    int max_comp = 0;

    for (int i = 1; i <= m; i++) {
        int u, v;
        fin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    function<void(const int, const int)> dfs_tarjan;
    dfs_tarjan = [&dfs_tarjan, graph, &seen, &low, &disc, &parent, &max_art_points, &max_comp]
            (const int u, const int time) {
        disc[u] = low[u] = time;
        seen[u] = true;
        int children = 0;

        for (auto v: graph[u]) {
            // back edge
            // in this case, we update low[u] using disc[v] as we are interested
            // in the earliest time we can reach u from v using exactly one back edge
            // (similar to a lower bound in the dfs tree)
            if (seen[v]) {
                low[u] = min(low[u], disc[v]);
            } else {
                ++children;
                parent[v] = u;
                dfs_tarjan(v, time + 1);

                // tree edge
                // in this case, we update low[u] using low[v] as we are interested
                // in the earliest time we can reach u from a child vertex which belongs
                // to the subtree rooted at u
                // (similar to an upper bound in the dfs tree)
                low[u] = min(low[u], low[v]);

                // if u is the root of the dfs tree or
                // u is not the root of the dfs tree and low[v] >= disc[u],
                // then u is an articulation point
                // (note that the number of connected components yielded after removing u
                // is equal to the number of times low[v] >= disc[u] is true + 1)
                if (parent[u] == 0 && children > 1 || parent[u] != 0 && low[v] >= disc[u]) {
                    ++max_art_points[u];
                    max_comp = max(max_comp, max_art_points[u]);
                }
            }
        }
    };

    dfs_tarjan(1, 1);
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (max_art_points[i] == max_comp) {
            res.emplace_back(i);
        }
    }

    fout << max_comp << " " << res.size() << "\n";
    for (auto u: res) {
        fout << u << " ";
    }

    fin.close(), fout.close();
    return 0;
}
