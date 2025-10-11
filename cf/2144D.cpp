#include <bits/stdc++.h>

using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    ll y;
    cin >> y;
    vector<ll> a(n);
    ll maxn = 0;
    for (auto &i : a) {
        cin >> i;
        maxn = max(maxn, i);
    }
    vector<int> cnt(2e5 + 5);
    ll ans = 0x3f3f3f3f3f3f3f;
    for (int x = 2; x <= maxn; x++) {
        vector<ll> need((maxn - 1) / x + 5);
        for (int i = (maxn - 1) / x + 1; i >= 1; i--) {
            need[(i - 1) / x + 1] += cnt[i];
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}