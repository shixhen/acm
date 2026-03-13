#include <bits/stdc++.h>

using namespace std;

void work(int x) {
    //cout << x << " ----\n";
    if (x == 0) {
        return;
    }
    if (x == 1) {
        cout << "1 1 ";
        return;
    }
    cout << "1 2 ";
    for (int i = 3; i <= x; i++) {
        cout << i << " " << i - 2 << " ";
    }
    cout << x - 1 << " " << x << " ";
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (k < n || k > ((n - 2) * 4 + 6) / 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int d = n - (((n - 2) * 4 + 6) / 2 - k);
    work(d);
    for (int i = d + 1; i <= n; i++) {
        cout << i << " " << i << " ";
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