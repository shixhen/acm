#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> l(n + 1);
    vector<long long> r(n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        ans += r[i] - l[i];
    }
    vector<array<long long, 3>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        ans += r[i];
        a[i] = {l[i] + r[i], l[i], r[i]};
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n / 2; i++) {
        ans -= a[i][0];
    }
    if (n % 2 == 0) {
        cout << ans << "\n";
        return;
    }
    long long k = 0x3f3f3f3f3f3f;
    for (int i = n / 2 + 1; i <= n; i++) {
        k = min(k, a[i][2]);
    }
    long long k2 = 0;
    for (int i = 1; i <= n / 2 + 1; i++) {
        k2 = max(a[i][1], k2);
    }
    cout << max(ans - k, ans - a[n / 2 + 1][0] + k2) << "\n";
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
