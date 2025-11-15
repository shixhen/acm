#include <bits/stdc++.h>

using namespace std;

bool f(int x) {
    while (x > 1) {
        if (x & 1) return false;
        x >>= 1;
    }
    return true;
}

void solve() {

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cout << f(4 - 1);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}