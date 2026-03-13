#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> a;

vector<int> ans;
map<int, int> mp;

int sum_key = 0;
int sum_val = 0;
void dfs(int u, int f) {
    sum_val++;
    if (!mp.count(a[u])) {
        mp[a[u]] = 1;
        sum_key++;
    } else {
        mp[a[u]]++;
    }
    if (sum_val > sum_key) {
        ans[u] = 1;
    }
    for (auto v : g[u]) {
        if (v != f) {
            dfs(v, u);
        }
    }
    mp[a[u]]--;
    if (mp[a[u]] == 0) {
        mp.erase(a[u]);
        sum_key--;
    }
    sum_val--;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    a.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    g.assign(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << (ans[i] ? "Yes" : "No") << "\n";
    }
    return 0;
}