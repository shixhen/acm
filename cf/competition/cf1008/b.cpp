#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k % 2) {
        for (int i = 1; i < n; i++) {
            cout << n << ' ';
        }
        cout << n - 1 << '\n';
    } else {
        for (int i = 1; i < n - 1; i++) {
            cout << n - 1 << ' ';
        }
        cout << n << ' ' << n - 1 << '\n';
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}