#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1000005;

vector<int> edge[N];
vector<long long> val, fa;
bool vis[N];
int mark;
long long dp[N][2];

void dfs(int u) {
    vis[u] = true;
    dp[u][0] = 0;
    dp[u][1] = val[u];
    for (int v : edge[u]) {
        if (v == mark) continue;
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int get_mark(int u) {
    vis[u] = true;
    u = fa[u];
    return vis[u] ? u : get_mark(u);
}

long long solve(int u) {
    long long res = 0;
    mark = get_mark(u);
    dfs(mark);
    res = dp[mark][0];
    mark = fa[mark];
    dfs(mark);
    res = max(res, dp[mark][0]);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    val.assign(n + 1, 0);
    fa.assign(n + 1, 0);
    for (int i = 1, u; i <= n; i++) {
        cin >> val[i];
        cin >> u;
        fa[i] = u;
        edge[u].push_back(i);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        ans += solve(i);
    }
    cout << ans;
    return 0;
}