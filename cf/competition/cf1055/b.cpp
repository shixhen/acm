#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void solve() {
    ll n, rk, ck, rd, cd;
    cin >> n >> rk >> ck >> rd >> cd;
    ll ans = -1;
    if (rk < rd) ans = max(ans, rd);
    else if (rk > rd) ans = max(ans, n - rd);

    if (ck < cd) ans = max(ans, cd);
    else if (ck > cd) ans = max(ans, n - cd);

    cout << ans << endl;
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