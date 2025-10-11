#include <bits/stdc++.h>

using namespace std;

constexpr int N = 100005;

vector<int> edge[N];
int depth[N];
int up[N][20]; // 2^j 上的祖先

void dfs(int u, int fa) {
    up[u][0] = fa;
    depth[u] = depth[fa] + 1;
    for (int j = 1; j < 20; j++) {
        up[u][j] = up[up[u][j - 1]][j - 1];
    }
    for (int v : edge[u]) {
        if (v != fa) {
            dfs(v, u);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    for (int j = 19; j >= 0; j--) {
        if (depth[up[u][j]] >= depth[v]) {
            u = up[u][j];
        }
    }
    if (u == v) {
        return u;
    }
    for (int j = 19; j >= 0; j--) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

// 判断一点是否在两点之间的路径
bool is_on_path(int u, int v, int x) {
    return (depth[x] >= depth[lca(u, v)] && (lca(u, x) == x || lca(v, x) == x));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0);
    int a, b, c, d;
    int u, v;
    while (q--) {
        cin >> a >> b >> c >> d;
        u = lca(a, b);
        v = lca(c, d);
        if (is_on_path(a, b, v) || is_on_path(c, d, u))
            cout << "Y\n";
        else
            cout << "N\n";
    }
    return 0;
}