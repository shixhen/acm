#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    if ((x + y) % 3) {
        cout << "NO\n";
        return;
    }
    if (y * 2 > x) {
        cout << "NO\n";
        return;
    }
    if (-y * 4 > x) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

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