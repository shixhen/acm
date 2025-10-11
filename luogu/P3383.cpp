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
long long a[N];       // 节点权值
vector<int> g[N];
int n, m, root, idx;
long long mod;

void build(int p, int l, int r) {
    if (l == r) {
        sum[p] = a[rk[l]] % mod;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    sum[p] = (sum[p << 1] + sum[p << 1 | 1]) % mod;
}

void push_down(int p, int l, int r) {
    if (lazy[p] == 0) return;
    int mid = (l + r) >> 1;
    lazy[p << 1] = (lazy[p << 1] + lazy[p]) % mod;
    lazy[p << 1 | 1] = (lazy[p << 1 | 1] + lazy[p]) % mod;
    sum[p << 1] = (sum[p << 1] + (mid - l + 1) * lazy[p] % mod) % mod;
    sum[p << 1 | 1] = (sum[p << 1 | 1] + (r - mid) * lazy[p] % mod) % mod;
    lazy[p] = 0;
}

void update(int p, int l, int r, int s, int t, long long v) {
    if (l > t || r < s) return;
    if (l >= s && r <= t) {
        lazy[p] = (lazy[p] + v) % mod;
        sum[p] = (sum[p] + (r - l + 1) * v % mod) % mod;
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
    sum[p] = (sum[p << 1] + sum[p << 1 | 1]) % mod;
}

long long query(int p, int l, int r, int s, int t) {
    if (l >= s && r <= t) return sum[p];
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    long long res = 0;
    if (s <= mid) {
        res += query(p << 1, l, mid, s, t);
    }
    if (t > mid) {
        res += query(p << 1 | 1, mid + 1, r, s, t);
    }
    return res % mod;
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

void add_path(int x, int y, long long z) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) {
            swap(x, y);
        }
        update(1, 1, n, dfn[top[x]], dfn[x], z);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) {
        swap(x, y);
    }
    update(1, 1, n, dfn[x], dfn[y], z);
}

void add_son(int x, long long z) {
    update(1, 1, n, dfn[x], dfn[x] + sz[x] - 1, z);
}

long long query_path(int x, int y) {
    long long res = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) {
            swap(x, y);
        }
        res = (res + query(1, 1, n, dfn[top[x]], dfn[x])) % mod;
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) {
        swap(x, y);
    }
    res = (res + query(1, 1, n, dfn[x], dfn[y])) % mod;
    return res;
}

long long query_son(int x) {
    return query(1, 1, n, dfn[x], dfn[x] + sz[x] - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> root >> mod;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= mod;
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(root, 0);
    dfs2(root, root);
    build(1, 1, n);
    int op, x, y;
    long long z;
    while (m--) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> z;
            z %= mod;
            add_path(x, y, z);
        } else if (op == 2) {
            cin >> x >> y;
            cout << query_path(x, y) << "\n";
        } else if (op == 3) {
            cin >> x >> z;
            z %= mod;
            add_son(x, z);
        } else {
            cin >> x;
            cout << query_son(x) << "\n";
        }
    }
    return 0;
}