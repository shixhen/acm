#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    if (x < y) {
        cout << 2 << '\n';
        return;
    }
    if (y == x || y <= 1 || (x - y) <= 1) {
        cout << "-1\n";
        return;
    }
    cout << "3\n";
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