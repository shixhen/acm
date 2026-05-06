#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<vector<int>> g2;
vector<int> dep;
vector<long long> ans;

void dfs(int u, int d) {
    dep[u] = d;
    for (auto &v : g[u]) {
        dfs(v, d + 1);
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    g.assign(n + 1, vector<int>());
    g2.assign(n + 1, vector<int>());
    ans.assign(n + 1, 0x3f3f3f3f);
    dep.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int v;
            cin >> v;
            g[i].push_back(v);
        }
    }
    dfs(1, 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g2[u].push_back(v);
    }
    // sort(edges.begin(), edges.end(), [&](auto &a, auto &b) {
    //     return dep[a.first] > dep[b.first];
    // });
    vector<int> flag(k);
    for (auto &x : flag) {
        cin >> x;
        ans[x] = 0;
    }
    vector<int> id(n + 1);
    iota(id.begin(), id.end(), 0);
    sort(id.begin() + 1, id.end(), [&](int x, int y) {
        return dep[x] > dep[y];
    });
    for (int i = 1; i <= n; i++) {
        int u = id[i];
        long long sum = 0;
        bool flag = true;
        for (auto v : g[u]) {
            if (ans[v] == 0x3f3f3f3f) {
                flag = false;
                break;
            }
            sum += ans[v];
        }
        if (flag && !g[u].empty()) {
            //cout << u << " " << ans[u] << " " << sum << "\n";
            ans[u] = min(ans[u], sum);
        }
        for (auto v : g2[u]) {
            if (ans[v] == 0x3f3f3f3f) {
                continue;
            }
            ans[u] = min(ans[u], ans[v] + 1);
        }
    }
    if (ans[1] >= 0x3f3f3f3f) {
        cout << -1 << "\n";
        return;
    }
    cout << ans[1] << "\n";
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();

    }
}


