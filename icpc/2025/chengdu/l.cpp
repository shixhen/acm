#include <bits/stdc++.h>

using namespace std;

constexpr int N = 200005;

int ans[N];
int a[N];
int b[N];
vector<int> edge[N];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        edge[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    vector<map<int, int>> mp(n + 1);
    vector<int> cnt(n + 1);
    auto dfs = [&] (auto &&self, int u, int f) -> void {
        int p = u;
        int maxn = 0;
        for (int v : edge[u]) {
            if (v == f) continue;
            self(self, v, u);
            if ((int)mp[v].size() > maxn) {
                maxn = mp[v].size();
                p = v;
            }
        }
        mp[u] = move(mp[p]);
        cnt[u] = cnt[p];
        for (int v : edge[u]) {
            if (v == f || v == p) continue;
            for (auto &[key, val] : mp[v]) {
                cnt[u] -= abs(mp[u][key]);
                mp[u][key] += val;
                cnt[u] += abs(mp[u][key]);
            }
        }
        cnt[u] -= abs(mp[u][a[u]]);
        mp[u][a[u]]++;
        cnt[u] += abs(mp[u][a[u]]);
        cnt[u] -= abs(mp[u][b[u]]);
        if (b[u] == 0) {
            mp[u][b[u]]++;
            if (mp[u][b[u]] == 0) {
                mp[u].erase(b[u]);
            }
        } else {
            //cout << u << " : " << mp[u][b[u]] << "\n";
            mp[u][b[u]]--;
            if (mp[u][b[u]] == 0) {
                mp[u].erase(b[u]);
            }
        }
        cnt[u] += abs(mp[u][b[u]]);
        //cout << u << " ----\n";
        ans[u] = (cnt[u] <= (mp[u][0] << 1));
        return;
    };
    dfs(dfs, 1, -1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
    }
    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}