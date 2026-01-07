#include <bits/stdc++.h>

using namespace std;



void solve() {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    int a = 1;
    int m = 0, n = 0;
    for (int i = 1; ; i++) {
        if (i % 2) {
            m += a;
        } else {
            n += a;
        }
        if (m > x || n > y) {
            ans = max(ans, i - 1);
            break;
        }
        a <<= 1;
    }
    a = 1;
    m = 0, n = 0;
    swap(x, y);
    for (int i = 1; ; i++) {
        if (i % 2) {
            m += a;
        } else {
            n += a;
        }
        if (m > x || n > y) {
            ans = max(ans, i - 1);
            break;
        }
        a <<= 1;
    }
    cout << ans << "\n";
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