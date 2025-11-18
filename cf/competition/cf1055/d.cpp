#include <bits/stdc++.h>

using namespace std;
using ll = long long;
bool f(int x) {
    while (x > 1) {
        if (x & 1) return false;
        x >>= 1;
    }
    return true;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<ll> b(n + 1);
    vector<ll> c(n + 1);
    vector<ll> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = log2(a[i]);
        // 2的幂+1
        if (a[i] != 2 && f(a[i] - 1)) {
            c[i] = 1;
            //cout << a[i] << " ";
        }
        // 不是2的幂且不是2的幂+1
        if (!f(a[i]) && !f(a[i] - 1)) {
            b[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        //cout << i << " " << b[i] << " " << c[i] << "\n";
        sum[i] += sum[i - 1];
        b[i] += b[i - 1];
        c[i] += c[i - 1];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        ll ans = 0;
        ans += sum[r] - sum[l - 1];
        //cout << " " << ans << "\n";
        ans += (c[r] - c[l - 1]) / 2;
        //cout << (c[r] - c[l - 1]) / 2 << "\n";
        ans += (b[r] - b[l - 1]);
        cout << ans << "\n";
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