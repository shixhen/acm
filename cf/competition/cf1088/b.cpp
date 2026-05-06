#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    int t = abs(x - y);
    int ans = 0;
    for (int i = 1; i * i <= t; i++) {
        if (t % i == 0) {
            ans++;
            if (i * i != t) {
                ans++;
            }
        }
    }
    if (x == y) {
        ans = 1;
    }
    cout << ans << "\n";
    while (x--) {
        cout << 1 << " ";
    }
    while (y--) {
        cout << -1 << " ";
    }
    cout << "\n";
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}