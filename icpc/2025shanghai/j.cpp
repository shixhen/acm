#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 5;

vector<int> g[N][9];

int tot, k;

void add(int x) {
    if (tot < k) {
        cout << x << "\n";
        tot++;
    }
    if (tot == k) {
        exit(0);
    }
}

void dfs(const vector<int>& edge, int d) {
    if (edge.empty()) {
        return;
    }
    for (int i = 1; i <= 8; i++) {
        vector<int> ne;
        for (auto &u : edge) {
            for (auto &v : g[u][i]) {
                add(d);
                ne.push_back(v);
            }
        }
        dfs(ne, d + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][w].push_back(v);
    }
    for (int i = 1; i <= 8; i++) {
        vector<int> edge;
        for (int j = 1; j <= n; j++) {
            for (auto &u : g[j][i]) {
                add(1);
                edge.push_back(u);
            }
        }
        dfs(edge, 2);
    }
    while (tot < k) {
        cout << -1 << "\n";
        tot++;
    }
    return 0;
}