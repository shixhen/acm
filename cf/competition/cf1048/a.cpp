#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << "\n";
        return;
    }
    if (a % b == 0 || b % a == 0) {
        cout << 1 << "\n";
        return;
    }
    cout << 2 << "\n";
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