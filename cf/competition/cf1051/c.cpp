#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> ind(n + 1);
    vector<vector<int>> edge(n + 1, vector<int>());
    for (int i = 1, u, v, x, y; i < n; i++) {
        cin >> u >> v >> x >> y;
        if (x >= y) {
            edge[v].push_back(u);
            ind[u]++;
        } else {
            edge[u].push_back(v);
            ind[v]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }
    vector<int> p(n + 1);
    int num = 1;
    while (!q.empty()) {
        int u = q.front();
        p[u] = num++;
        q.pop();
        for (auto &v : edge[u]) {
            p[v] = u;
            ind[v]--;
            if (ind[v] == 0) {
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " \n"[i == n];
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) { solve(); }
    return 0;
}