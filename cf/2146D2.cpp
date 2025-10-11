#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int bitwidth(int x) {
    return 31 - __builtin_clz(x);
}

void solve() {
    int l, r;
    cin >> l >> r;
    vector<ll> a(r - l + 1);
    function<void(int, int)> dfs = [&] (int ll, int rr) {
        if (ll > rr) {
            return;
        }
        if (ll == rr) {
            a[ll - l] = rr;
            return;
        }
        int t = bitwidth(ll ^ rr);
        t = (rr >> t) << t;
        for (int i = t; i <= rr; i++) {
            if (i > rr) {
                dfs(ll, 2 * t - i - 1);
                return;
            }
            if (2 * t - i - 1 < ll) {
                dfs(i, rr);
                return;
            }
            a[i - l] = 2 * t - i - 1;
            a[2 * t - i - 1 - l] = i;
        }
        dfs(ll, 2 * t - rr - 2);
        return;
    };
    dfs(l, r);
    ll res = 0;
    for (ll i = 0; i < r - l + 1; i++) {
        res += i + l | a[i];
    }
    cout << res << "\n";
    for (auto &i : a) {
        cout << i << " ";
    }
    cout << "\n";
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