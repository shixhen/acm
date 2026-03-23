#include <bits/stdc++.h>

using namespace std;

int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++) {
        if (ask(2 * i - 1, 2 * i)) {
            cout << "! " << 2 * i << endl;
            cout.flush();
            return;
        }
    }
    if (ask(1, 2)) {
        cout << "! " << 1 << endl;
        cout.flush();
        return;
    }
    if (ask(1, 3)) {
        cout << "! " << 1 << endl;
        cout.flush();
        return;
    }
    if (ask(2, 3)) {
        cout << "! " << 2 << endl;
        cout.flush();
        return;
    }
    cout << "! " << 4 << endl;
    cout.flush();
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