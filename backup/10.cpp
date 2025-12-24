#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> f(n + 1);
        vector<vector<int>> edge(n + 1);
        for (int i = 1; i <= n; i++) {
            f[i] = i;
        }
        function<int(int)> find = [&](int x) {
            return f[x] == x ? x : f[x] = find(f[x]);
        };
        int u, v;
        int num = 0;
        vector<int> st(n + 1);
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
            u = find(u);
            v = find(v);
            if (u != v) {
                f[u] = v;
            } else {
                st[v]++;
            }
        }
        for (int i = 1; i <= n; i++) {
            u = find(i);
            if (u != i) {
                st[u] += st[i];
                st[i] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (st[i] == 1)
                num++;
        }

        if (num != 1) {
            cout << "No " << num << "\n";
            continue;
        }
        vector<int> cnt(n + 1);
        int ans = 0;
        
        function<void(int, int)> dfs = [&](int u, int fa) {
            if (ans)
                return;
            for (int v : edge[u]) {
                if (ans)
                    return;
                if (v != fa) {
                    if (cnt[v])
                        ans = cnt[u] - cnt[v] + 1;
                    else
                        cnt[v] = cnt[u] + 1;
                    dfs(v, u);
                }
            }
        };
        for (int i = 1; i <= n; i++) {
            if (ans)
                break;
            cnt[i] = 1;
            dfs(i, 0);
        }
        cout << "Yes " << ans << "\n";
    }
    return 0;
}