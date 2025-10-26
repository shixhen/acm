#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i += 2) {
        a[i] = max(a[i], a[i - 1]);
        if (i > 2) a[i] = max(a[i], a[i - 2]);
    }
    long long ans = 0;
    long long t;
    for (int i = 1; i <= n; i += 2) {
        t = 0x3f3f3f3f3f;
        if (i > 1) {
            t = min(t, a[i - 1]);
        }
        if (i < n) {
            t = min(t, a[i + 1]);
        }
        ans += max(0ll, a[i] - t + 1);
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
