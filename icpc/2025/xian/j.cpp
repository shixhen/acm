#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> c(n + 1);
    vector<vector<int>> edge(n + 1, vector<int>());
    vector<int> dep(n + 1);
    vector<vector<int>> f(n + 1, vector<int> (20));
    vector<vector<long long>> co(n + 1, vector<long long> (20));
    vector<long long> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    function<void(int, int)> dfs = [&] (int u, int fa) {
        dep[u] = dep[fa] + 1;
        f[u][0] = fa;
        for (int i = 1; i < 20; i++) {
            f[u][i] = f[f[u][i - 1]][i - 1];
        }
        long long t = 0;
        for (auto v : edge[u]) {
            if (v != fa) {
                dfs(v, u);
                t += c[v];
            }
        }
        if (t) {
            s[u] = t;
            c[u] = min(c[u], t);
        }
    };
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        //cout << i << " " << c[i] << "   -   " << s[f[i][0]] << endl;
        co[i][0] = s[f[i][0]] - c[i];
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 2; j <= n; j++) {
            co[j][i] = co[j][i - 1] + co[f[j][i - 1]][i - 1];
        }
    }
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        long long ans = 0;
        //cout << x << " " << y << "\n";
        for (int j = 19; j >= 0; j--) {
            if (dep[f[x][j]] >= dep[y]) {
                //cout << x << endl;
                ans += co[x][j];
                x = f[x][j];
                //cout << x << endl;
            }
        }
        if (x != y) {
            cout << -1 << "\n";
        } else {
            cout << ans << "\n";
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}