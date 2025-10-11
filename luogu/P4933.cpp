#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = 998244353;

long long dp[1005][40005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long add = 20000;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans++;
        for (int j = i - 1; j >= 1; j--) {
            dp[i][a[j] - a[i] + add] += dp[j][a[j] - a[i] + add] + 1;
            dp[i][a[j] - a[i] + add] %= mod;
            ans += dp[j][a[j] - a[i] + add] + 1;
            ans %= mod;
        }
    }
    cout << ans << "\n";
    return 0;
}