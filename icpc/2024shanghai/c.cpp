#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    if ((l << 1) == r) {
        cout << "Alice\n";
        return;
    }
    if ((l << 1) > r) {
        cout << (((r - l) & 1) ? "Bob\n" : "Alice\n");
        return;
    }
    cout << ((l & 1) ? "Alice\n" : "Bob\n");
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}