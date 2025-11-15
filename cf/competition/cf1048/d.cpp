#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> dp(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];  
    }
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2]);
        if ((a[i] < a[i - 1] && a[i - 2] > a[i - 1])) {
            dp[i] = i - 2;
        }
    }
    int l, r;
    while (q--) {
        cin >> l >> r;
        if (l <= dp[r]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
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