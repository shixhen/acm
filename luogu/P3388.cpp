#include <bits/stdc++.h>

using namespace std;

constexpr int N = 20005;

int n, m;
int dfn[N], low[N], idx, cnt;
bool vis[N], flag[N];
vector<int> edge[N];

void tarjan(int u, int fa) {
    vis[u] = true;
    low[u] = dfn[u] = ++idx;
    int child = 0;
    for (const auto &v : edge[u]) {
        if (!vis[v]) {
            child++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (fa != u && low[v] >= dfn[u] && !flag[u]) {
                flag[u] = true;
                cnt++;
            }
        } else if (v != fa) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (u == fa && child > 1 && !flag[u]) {
        flag[u] = true;
        cnt++;
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            tarjan(i, i);
        }
    }
    cout << cnt << "\n";
    for (int i = 1; i <= n; i++) {
        if (flag[i]) cout << i << " ";
    }
    return 0;
}