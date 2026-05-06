#include <bits/stdc++.h>

using namespace std;
vector<long long> p;
int n;

vector<vector<long long>> dp;

long long dfs(int i, int j) {
    if (i + 1 == j) return dp[i][j] = 0;
    if (dp[i][j] != 0x3f3f3f3f3f3f3f3f) return dp[i][j];
    long long res = 0x3f3f3f3f3f3f3f3f;
    for (int k = i + 1; k < j; k++) {
        res = min(res, dfs(i, k) + dfs(k, j) + p[i] * p[k] * p[j]);
    }
    return dp[i][j] = res;
}

int main() {
    while (cin >> n) {
        long long ans = 0;
        p.resize(n + 1);
        dp.assign(n + 2, vector<long long>(n + 2, 0x3f3f3f3f3f3f3f3f));
        for (int i = 0; i <= n; i++) {
            cin >> p[i];
        }
        ans = dfs(0, n);
        cout << ans << endl;
    }

    return 0;
}