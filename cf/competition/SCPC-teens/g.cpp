#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    for (auto &i : a) {
        cin >> i;
        mp[i]++;
    }
    ll ans = 0;
    for (auto &it : mp) {
        if (it.second >= 3) {
            ans += (it.second * (it.second - 1) * (it.second - 2)) / 6;
        }
        if (it.second >= 2 && mp.count(it.first * 2)) {
            ans += ((it.second * (it.second - 1)) / 2 * mp[it.first * 2]);
        }
    }
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