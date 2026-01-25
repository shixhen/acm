#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, x;
    cin >> n >> x;
    vector<long long> a(n + 1), b(n + 1), c(n + 1);
    long long ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        x -= a[i] * (b[i] - 1);
    }
    if (x <= 0) {
        cout << 0 << "\n";
        return;
    }
    //cout << x << "\n";
    for (int i = 1; i <= n; i++) {
        if (a[i] * b[i] <= c[i]) {
            continue;
        }
        long long t = x / (a[i] * b[i] - c[i]);
        if (x % (a[i] * b[i] - c[i]) != 0) {
            t++;
        }
        ans = min(ans, t);
    }
    if (ans == 0x3f3f3f3f3f3f3f3f) ans = -1;
    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}