#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a)
        cin >> i;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (i <= n / 2) {
            ans += n + i;
        } else {
            ans += (2 * n - i - 1 - (n % 2 == 0 ? 1 : 0));
        }
    }
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            if (i <= n / 2) {
                ans -= (n - 2 + i);
            } else {
                ans -= (2 * n - i - 1);
            }
        }
    }
    cout << ans << "\n";
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