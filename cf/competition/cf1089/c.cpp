#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        long long x = __gcd(a[i], a[i - 1]);
        long long y = __gcd(a[i], a[i + 1]);
        long long z = __gcd(x, y);
        if (x * y / z < a[i]) ans++;
    }
    if (__gcd(a[0], a[1]) < a[0]) ans++;
    if (__gcd(a[n - 1], a[n - 2]) < a[n - 1]) ans++;
    cout << ans;
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}