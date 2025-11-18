#include <bits/stdc++.h>

using namespace std;
vector<int> edge[100005];
unordered_map<int, unordered_map<int, bool>> mp;
vector<int> ans;

void dfs(int x) {
    for (int i = 0; i < edge[x].size(); i++) {
        if (mp[x][edge[x][i]]) continue;
        mp[edge[x][i]][x] = true;
        mp[x][edge[x][i]] = true;
        dfs(edge[x][i]);
    }
    ans.push_back(x);
}

void solve() {
    int n, st, en, u, v;
    mp.clear();
    ans.clear();
    cin >> n >> st >> en;
    for (int i = 0; i <= n + 1; i++) edge[i].clear();
    int k = n - 1;
    while (k--) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(en);
    for (auto &i: ans) cout << i << " ";
    cout << '\n';
    return;  
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}