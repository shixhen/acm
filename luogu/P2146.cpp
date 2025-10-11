#include <bits/stdc++.h>

using namespace std;

constexpr int N = 100005;

long long lazy[N << 2], sum[N << 2];  // 懒标记和线段树和
int sz[N];      // 子树大小
int fa[N];      // 父节点
int top[N];     // 头节点
int son[N];     // 重儿子
int dfn[N];     // DFS序
int dep[N];     // 深度
int rk[N];      // 序号到节点的映射
vector<int> g[N];
int n, idx;

void build(int p, int l, int r) {
    if (l == r) {
        sum[p] = 0;
        lazy[p] = -1;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    sum[p] = (sum[p << 1] + sum[p << 1 | 1]);
}

void push_down(int p, int l, int r) {
    if (lazy[p] == -1) return;
    int mid = (l + r) >> 1;
    lazy[p << 1] = lazy[p];
    lazy[p << 1 | 1] = lazy[p];
    sum[p << 1] = (mid - l + 1) * lazy[p];
    sum[p << 1 | 1] = (r - mid) * lazy[p];
    lazy[p] = -1;
}

void update(int p, int l, int r, int s, int t, int v) {
    if (l > t || r < s) return;
    if (l >= s && r <= t) {
        lazy[p] = v;
        sum[p] = (r - l + 1) * v;
        return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (s <= mid) {
        update(p << 1, l, mid, s, t, v);
    }
    if (t > mid) {
        update(p << 1 | 1, mid + 1, r, s, t, v);
    }
    sum[p] = (sum[p << 1] + sum[p << 1 | 1]);
}

int query(int p, int l, int r, int s, int t, int v) {
    if (l >= s && r <= t) {
        return (v ? sum[p] : r - l + 1 - sum[p]);
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    int res = 0;
    if (s <= mid) {
        res += query(p << 1, l, mid, s, t, v);
    }
    if (t > mid) {
        res += query(p << 1 | 1, mid + 1, r, s, t, v);
    }
    return res;
}

void dfs1(int u, int f) {
    fa[u] = f;
    dep[u] = dep[f] + 1;
    sz[u] = 1;
    for (int v : g[u]) {
        if (v == f) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (son[u] == 0 || sz[v] > sz[son[u]]) {
            son[u] = v;
        }
    }
}

void dfs2(int u, int t) {
    top[u] = t;  // 设置重链顶点
    dfn[u] = ++idx;
    rk[idx] = u;
    if (!son[u]) return;
    dfs2(son[u], t);  // 继续重儿子
    for (int v : g[u]) {
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

void add_path(int x) {
    while (top[x] != top[0]) {
        update(1, 1, n, dfn[top[x]], dfn[x], 1);
        x = fa[top[x]];
    }
    update(1, 1, n, dfn[0], dfn[x], 1);
}

void add_son(int x) {
    update(1, 1, n, dfn[x], dfn[x] + sz[x] - 1, 0);
}

int query_path(int x) {
    int res = 0;
    while (top[x] != top[0]) {
        res = (res + query(1, 1, n, dfn[top[x]], dfn[x], 0));
        x = fa[top[x]];
    }
    res = res + query(1, 1, n, dfn[0], dfn[x], 0);
    return res;
}

int query_son(int x) {
    return query(1, 1, n, dfn[x], dfn[x] + sz[x] - 1, 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1, u; i < n; i++) {
        cin >> u;
        g[u].push_back(i);
    }
    dfs1(0, 0);
    dfs2(0, 0);
    build(1, 1, n);
    int q;
    cin >> q;
    string s;
    int x;
    while (q--) {
        cin >> s >> x;
        if (s[0] == 'i') {
            cout << query_path(x) << "\n";
            
            add_path(x);
        } else {
            cout << query_son(x) << "\n";
            add_son(x);
        }
    }
    return 0;
}