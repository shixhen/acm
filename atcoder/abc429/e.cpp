#include <bits/stdc++.h>

using namespace std;
constexpr int N = 2e5 + 5;
vector<int> edge[N];
int v[N];
bool vis[N];
int ans[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    queue<array<int, 3>> q;
    string s;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'S') {
            q.push({i, i, 0});
            v[i] = i;
        }
    }
    while (!q.empty()) {
        auto [now, u, d] = q.front();
        q.pop();
        for (auto &to : edge[now]) {
            if (vis[to] || v[to] == u) continue;
            if (v[to] == 0) {
                v[to] = u;
            } else {
                vis[to] = 1;
            }
            ans[to] += d + 1;
            q.push({to, u, d + 1});
        }
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'D') {
            cout << ans[i] << "\n";
        }
    }
    return 0;
}