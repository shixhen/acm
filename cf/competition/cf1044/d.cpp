#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long ans = 0;
    for (auto &i : a) {
        cin >> i;
        ans += i;
    }
    ans++;
    ans -= n;
    vector<long long> dp(n + 1);
    long long maxn = 0;
    for (long long i = 1; i < n; i++) {
        if (min(a[i], i) > 2) {
            dp[i] = max(dp[i - 2] + (min(a[i], i) - 2ll), dp[i - 1]);
            maxn = max(dp[i], maxn);
        }
    }
    cout << ans - maxn << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}