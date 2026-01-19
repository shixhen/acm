#include <bits/stdc++.h>

using namespace std;


long long n, m, k;

bool check(long long l, long long r) {
    long long x = min(l, r) - 1 + max(l, r) + max(l, r);
    return x <= m;
}

void solve() {
    cin >> n >> m >> k;
    if (k == 1 || k == n) {
        cout << min(n, (m - 1ll) / 2ll + 2ll) << "\n";
        return;
    }
    for (int i = 2; i <= n; i++) {
        bool f = true;
        for (int l = k - 1; l >= 0; l--) {
            long long r = i - l - 1;
            if (r > n - k) {
                break;
            }
            if (check(l, r)) {
                f = false;
                break;
            }
        }
        if (f) {
            cout << i - 1 << "\n";
            return;
        }
    }
    cout << n << "\n";
    // long long x = min(k - 1, n - k);
    // long long y = max(k - 1, n - k);
    // if (x * 2ll - 1ll >= m) {
    //     cout << m / 2ll + 2ll << "\n";
    //     return;
    // }
    // long long ans = x;
    // m -= x * 2ll - 1ll;
    // //cout << m << " " << y * 2ll - x << "\n";
    // if (y * 2ll - x >= m) {
    //     if (m <= x) {
    //         cout << min(n, ans + m + 1) << "\n";
    //         return;
    //     }
    //     cout << ans + (m + x) / 2ll + 1ll << "\n";
    //     return;
    // }
    // cout << n << "\n";
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