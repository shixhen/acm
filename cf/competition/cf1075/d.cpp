#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = 1e9 + 7;

void solve() {
    long long n, c;
    cin >> n >> c;
    string s;
    cin >> s;
    long long ans = 1;
    long long rem = 1;
    if (s[0] == '0' || s.back() == '0') {
        cout << -1 << "\n";
        return;
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            ans = (ans * i) % mod;
            rem = (rem * i) % c;
        } else {
            ans = (ans * 2ll) % mod;
            rem = (rem * 2ll) % c;
        }
    }
    if (rem == 0) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }
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