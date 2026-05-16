#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>());
    vector<string> s(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        g[i].push_back(i);
    }
    int w;
    cin >> w;
    vector<vector<int>> vis(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    bool flag = false;
    function<void(int, int, int)> dfs = [&](int u, int d, int idx) {
        if (vis[u][d] == idx) {
            flag = true;
            return;
        }
        if (vis[u][d] != 0) {
            return;
        }
        vis[u][d] = idx;
        for (int v : g[u]) {
            int to = d % w + 1;
            if (s[v][to] == 'o') {
                dfs(v, to, idx);
            }
        }
        vis[u][d] = -idx;
    };
    for (int i = 1; i <= n; i++) {
        if (s[i][1] == 'x' || vis[i][1]) continue;

        dfs(i, 1, i);
        if (flag) {
            cout << "Yes" << "\n";
            return;
        }
        // queue<pair<int, int>> q;
        // q.push({i, 1});
        // while (!q.empty()) {
        //     int u = q.front().first;
        //     int d = q.front().second;
        //     //cout << i << " " << u << " " << d << endl;
        //     q.pop();
        //     if (vis[u][d] != 0) {
        //         continue;
        //     }
        //     vis[u][d] = i;
        //     for (int v : g[u]) {
        //         int to = d % w + 1;
        //         if (s[v][to] == 'o') {
        //             q.push({v, to});
        //         }
        //     }
        // }
    }
    cout << "No" << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}