#include <bits/stdc++.h>

using namespace std;

constexpr long long mod =  998244353;


void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    vector<long long> cnt(5005);
    vector<long long> dp(n + 1);
    long long maxn = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxn = max(maxn, ++cnt[a[i]]);
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) continue;
        for (int j = n; j >= cnt[i]; j--) {
            dp[j] = (dp[j] + dp[j - cnt[i]] * cnt[i]) % mod;
        } 
    }
    long long ans = 0;
    for (int i = maxn; i <= n; i++) {
        ans = (ans + dp[i]) % mod;
    }
    cout << ans << "\n";
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