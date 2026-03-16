#include <bits/stdc++.h>

using namespace std;

void solve() {
    int h, w, q;
    cin >> h >> w >> q;
    for (int i = 0; i < q; i++) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            cout << x * w << "\n";
            h -= x;
        } else {
            cout << x * h << "\n";
            w -= x;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}