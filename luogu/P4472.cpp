#include <bits/stdc++.h>

using namespace std;

constexpr int N = 300005;
constexpr long long mod = 998244353;

vector<int> edge[N];
int depth[N];
int up[N][20]; // 2^j 上的祖先
long long pre[N][51];


long long qpow(long long a, long long t) {
    long long res = 1;
    while (t) {
        if (t & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        t >>= 1;
    }
    return res;
}


void dfs(int u, int fa) {
    up[u][0] = fa;
    depth[u] = depth[fa] + 1;
    for (int j = 1; j < 20; j++) {
        up[u][j] = up[up[u][j - 1]][j - 1];
    }

    for (int i = 1; i <= 50; i++) {
        pre[u][i] = (pre[fa][i] + qpow(depth[u], i)) % mod;
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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    depth[0] = -1;

    dfs(1, 0);
   
    cin >> q;
    int i, j, k;
    int l;
    long long ans = 0;
    while (q--) {
        cin >> i >> j >> k;
        l = lca(i, j);
        ans = (pre[i][k] + pre[j][k] - pre[l][k] - pre[up[l][0]][k] + 3 * mod) % mod;
        cout << ans << "\n";
    }
    return 0;
}