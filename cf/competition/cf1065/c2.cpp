#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> suma(35), sumb(35);
    int cnta = 0, cntb = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int j = 1;
        t = a[i];
        while (t) {
            if (t & 1) {
                suma[j]++;
            }
            t >>= 1;
            j++;
        }

    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        int j = 1;
        t = b[i];
        while (t) {
            if (t & 1) {
                suma[j]++;
            }
            t >>= 1;
            j++;
        }
    }
    int j = 33;
    for (; j >= 1; j--) {
        //cout << suma[j] << " " << sumb[j] << "\n";
        if (suma[j] % 2 != sumb[j] % 2) {
            break;
        }
    }
    if (j == 0) {
        cout << "Tie\n";
        return;
    }
    for (int i = n - 1; i >= 0; i--) {
        if ((a[i] & (1 << (j - 1))) != (b[i] & (1 << (j - 1)))) {
            if (i % 2) {
                cout << "Mai\n";
            } else {
                cout << "Ajisai\n";
            }
            return;
        }
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