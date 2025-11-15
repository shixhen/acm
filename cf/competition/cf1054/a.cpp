#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    int cnt0 = 0, cntz = 0;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (x == 0) cnt0++;
        if (x == -1) cntz++;
    }
    cout << cnt0 + (cntz % 2) * 2 << "\n";
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