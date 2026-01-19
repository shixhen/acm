#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int f = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i == 1 || i == n) {
            if (x != 1) {
                f++;
            }
        }
    }
    cout << ((f != 2) ? "Alice\n" : "Bob\n");
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}