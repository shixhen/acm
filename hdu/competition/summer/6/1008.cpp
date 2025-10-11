#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> dp((1 << m));
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1));
    vector<vector<ll>> dp2((1 << m), vector<ll>(k + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        vector<int> temp((1 << m));
        for (int j = 1; j <= m; j++) {
            for (int p = 0; p < (1 << m); p++) {
                temp[p | (1 << (j - 1))] = temp[p] + a[i][j];
                dp[p | (1 << (j - 1))] = max(dp[p | (1 << (j - 1))], temp[p | (1 << (j - 1))]);
            }
        }
    }
   
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}