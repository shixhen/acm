#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i % 2 == 0) {
            a[i] = -a[i];
        }
        ans += a[i];
    }
    vector<ll> suf1(n + 2, -1e12);
    vector<ll> suf2(n + 2, -1e12);
    vector<ll> pre2(n + 2, -1e12);
    vector<ll> pre1(n + 2, -1e12);
    ll add = 0;
    for (int i = n; i >= 1; i--) {
        if (i % 2 == 0) {
            suf1[i] = max(suf1[i + 1], suf1[i]);
            suf2[i] = max(suf2[i + 1], a[i] * -2ll + i);
        } else {
            suf1[i] = max(suf1[i + 1], a[i] * -2ll + i);
            suf2[i] = max(suf2[i + 1], suf2[i]);
        }
        
    }
    for (int i = 1; i <= n; i++) {
        if (i % 2) {
            pre1[i] = max(pre1[i - 1], pre1[i]);
            pre2[i] = max(pre2[i - 1], a[i] * -2ll - i);
        } else {
            pre1[i] = max(pre1[i - 1], a[i] * -2ll - i);
            pre2[i] = max(pre2[i - 1], pre2[i]);
        }
        
    }
    for (int i = 1; i <= n; i++) {
        add = max(add, suf1[i] + pre1[i]);
        add = max(add, suf2[i] + pre2[i]);
    }
    if (n % 2) {
        add = max(add, (long long) n - 1);
    } else {
        add = max(add, (long long) n - 2);
    }
    ans += add;
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