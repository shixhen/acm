#include <bits/stdc++.h>

using namespace std;


// 树链剖分求最近公共祖先
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> g(n + 1, vector<int>());
    int x, y;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> dep(n + 1); // 深度
    vector<int> fa(n + 1); // 父节点
    vector<int> sz(n + 1); // 子树大小
    vector<int> son(n + 1); // 重儿子
    vector<int> top(n + 1); // 重链顶点

    function<void(int, int)> dfs1 = [&](int u, int f) {
        fa[u] = f;
        dep[u] = dep[f] + 1;
        sz[u] = 1;
        for (int v : g[u]) {
            if (v == f)
                continue;
            dfs1(v, u);
            sz[u] += sz[v];
            if (son[u] == 0 || sz[v] > sz[son[u]]) {
                son[u] = v; // 更新重儿子
            }
        }
    };

    function<void(int, int)> dfs2 = [&](int u, int t) {
        top[u] = t; // 设置重链顶点
        if (son[u] != 0) {
            dfs2(son[u], t); // 继续重儿子
        }
        for (int v : g[u]) {
            if (v == fa[u] || v == son[u])
                continue; // 跳过父节点和重儿子
            dfs2(v, v); // 设置非重儿子的顶点为自己的顶点
        }
    };

    function<int(int, int)> lca = [&] (int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) {
                swap(u, v);
            }
            u = fa[top[u]]; // 上升到重链顶点的父节点
        }
        return dep[u] < dep[v] ? u : v;
    };

    dfs1(s, 0);
    dfs2(s, s);
    while (m--) {
        cin >> x >> y;
        cout << lca(x, y) << "\n"; // 输出最近公共祖先
    }
    return 0;
}