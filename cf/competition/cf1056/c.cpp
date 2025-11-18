#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    bool ok = true;
    bool f2 = true;
    bool f = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i > 1 && a[i] != a[i - 1]) {
            f2 = false;
        }
        if (i > 1 && abs(a[i] - a[i - 1]) > 1) {
            f = false;
        }
    }
    if (n % 2) {
        for (int i = 1; i <= n; i++) {
            if (a[i] != n / 2 + 1) {
                ok = false;
            }
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (a[i] != n / 2 + 1 && a[i] != n / 2) {
                ok = false;
            }
        }
    }
    
    if (ok && f2) {
        cout << (n % 2 ? 2 : 1) << "\n";
        return;
    }
    if (f2) {
        cout << 0 << "\n";
        return;
    }
    if (!f) {
        cout << 0 << "\n";
        return;
    }
    vector<int> b(n + 1);
    f = true;
    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i - 1] + 1) {
            if (b[i - 1] == 1 || b[i] == 1) {
                f = false;
                break;
            }
            b[i] = b[i - 1] = 2;
        }
        if (a[i] == a[i - 1] - 1) {
            if (b[i - 1] == 2 || b[i] == 2) {
                //cout << i << "   "  << 1111 << "\n";
                f = false;
                break;
            }
            b[i] = b[i - 1] = 1;
        }
        if (a[i] == a[i - 1]) {
            if (b[i - 1] == 1) {
                b[i] = 2;
            } else if (b[i - 1] == 2) {
                b[i] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] == a[i + 1]) {
            b[i] = 3 - b[i + 1];
        }
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i - 1]) {
            b[i] = 3 - b[i - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        cnt += (b[i] == 1);
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] == 2) {
            cnt++;
        }
        if (i > 1 && b[i - 1] == 1) {
            cnt--;
        }
        if (cnt != a[i]) {
            f = false;
            break;
        }
    }
    if (f) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }
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