#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        b[i] = i;
    }
    b[l - 1] = b[r];
    for (int i = 1; i <= n; i++) {
        a[i] = b[i] ^ b[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    return;
}

int main() {
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}