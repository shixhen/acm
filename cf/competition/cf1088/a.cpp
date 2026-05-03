#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    if (n == 2) {
        cout << "2 2" << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        cout << 2 << " ";
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