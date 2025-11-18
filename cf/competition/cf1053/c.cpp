#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<ll> k1(n * 2 + 2);
    vector<ll> k2(n * 2 + 2);
    vector<ll> pre(n * 2 + 3);
    vector<ll> suf(n * 2 + 3);
    vector<ll> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
        if (i % 2) {
            k1[i] -= a[i];
        } else {
            k1[i] += a[i];
        }
        pre[i] += a[i];
        suf[i] += a[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        k1[i] += k1[i - 1];
        pre[i] += pre[i - 1];
        suf[i] += suf[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        if (i % 2) {
            cout << suf[2 * n] - suf[2 * n - i + 1] - pre[i - 1] + k1[2 * n - i + 1] - k1[i - 1] << " ";
        } else {
            cout << suf[2 * n] - suf[2 * n - i + 1] - pre[i - 1] + (k1[i - 1] - k1[2 * n - i + 1]) << " ";
        }
    }
    cout << "\n";
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