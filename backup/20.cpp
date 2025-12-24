#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void solve() {
    ll h, d;
    cin >> h >> d;
    if (h == 1) {
        cout << d * 2 << "\n";
        return;
    }
    ll l = 0, r = d - 1;
    auto check = [&] (ll x) {
        ll a = d / (x + 1);
        ll b = d % (x + 1);
        ll sum = (1ll + a) * a / 2 * (x + 1 - b);
        sum += (1ll + a + 1) * (a + 1) / 2 * b;
        return sum < h + x;
    };
    ll mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l + d << "\n";
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
}