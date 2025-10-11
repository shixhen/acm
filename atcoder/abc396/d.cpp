#include <bits/stdc++.h>

using namespace std;
vector<int> edge[15];
bool vis[15];
unordered_map<int, unordered_map<int, long long>> mp;
long long ans = LONG_LONG_MAX;
long long temp = 0;
int n;
void dfs(int x) {
    for (int i = 0; i < edge[x].size(); i++) {
        if (vis[edge[x][i]]) continue;
        vis[edge[x][i]] = true;
        temp ^= mp[x][edge[x][i]];
        if (edge[x][i] == n) ans = min(ans, temp);
        dfs(edge[x][i]);
        vis[edge[x][i]] = false;
        temp ^= mp[x][edge[x][i]];
    }
    return;
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    long long m, u, v, w;
    cin >> m;
    while(m--) {
        cin >> u >> v >> w;
        edge[u].push_back(v);
        edge[v].push_back(u);
        mp[u][v] = w;
        mp[v][u] = w;
    }
    vis[1] = true;
    dfs(1);
    cout << ans;
    return 0;
}