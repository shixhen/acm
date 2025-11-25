#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    int cnta = 0, cntb = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnta += a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        cntb += b[i];
    }
    if (cnta % 2 == cntb % 2) {
        cout << "Tie\n";
        return;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] != b[i]) {
            if (i % 2) {
                cout << "Mai\n";
            } else {
                cout << "Ajisai\n";
            }
            return;
        }
    }
    if (cnta % 2) {
        cout << "Ajisai\n";
    } else {
        cout << "Mai\n";
    }
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