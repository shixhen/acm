#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 3;

int vis[N];
vector<int> primes[N];

int ans[N];

vector<int> g[N];
int sz[N];
int son[N];
int dfn[N];
int top[N];
int dep[N];
int fa[N];
int tot;

vector<int> p[N];

int tree[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int v) {
    for (int i = x; i < N; i += lowbit(i)) {
        tree[i] += v;
    }
    return;
}

int query(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        res += tree[i];
    }
    return res;
}

void dfs1(int u) {
    sz[u] = 1;
    for (auto &v : g[u]) {
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v);
        
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]]) {
            son[u] = v;
        }
    }
}

void dfs2(int u) {
    dfn[u] = ++tot;
    if (son[u]) {
        top[son[u]] = top[u];
        dfs2(son[u]);
    }
    for (auto &v : g[u]) {
        if (v != son[u]) {
            top[v] = v;
            dfs2(v);
        }
    }
}

void init() {
    primes[1] = {1};
    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            for (int j = i; j < N; j += i) {
                vis[j] = 1;
                primes[j].push_back(i);
            }
        }
    }
    return;
}

void solve() {
    int n, c1;
    cin >> n >> c1;
    for (int i = 1; i <= n; i++) {
        ans[i] = 1;
    }
    ans[1] = c1;
    vector<array<int, 3>> q(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> q[i][0] >> q[i][1] >> q[i][2]; 
        g[q[i][2]].push_back(i);
        for (auto &pr : primes[q[i][0]]) {
            p[pr].push_back(i);
        }
    }
    top[1] = 1;
    dep[1] = 1;
    dfs1(1);
    dfs2(1);
    for (int i = 2; i < N; i++) {
        if (p[i].empty()) continue;
        int cnt = 0;
        vector<pair<int, int>> temp;
        int t = c1;
        while (t % i == 0) {
            t /= i;
            cnt++;
        }
        add(1, cnt);
        temp.push_back({1, cnt});
        for (auto &idx : p[i]) {
            int u = q[idx][1];
            int v = q[idx][2];
            int sum = 0;
            while (top[v] != top[u]) {
                if (dep[top[v]] < dep[top[u]]) {
                    swap(u, v);
                }
                sum += query(dfn[v]) - query(dfn[top[v]] - 1);
                v = fa[top[v]];
            }
            if (dep[u] > dep[v]) {
                swap(u, v);
            }
            sum += query(dfn[v]) - query(dfn[u] - 1);
            t = q[idx][0];
            cnt = 0;
            while (t % i == 0) {
                t /= i;
                cnt++;
            }
            cnt -= sum;
            if (cnt <= 0) continue;
            add(dfn[idx], cnt);
            temp.push_back({dfn[idx], cnt});
            while (cnt--) {
                ans[idx] *= i;
            }
        }
        for (auto &[pos, val] : temp) {
            add(pos, -val);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int _ = 1;
    //cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}