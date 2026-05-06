#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < k; i++) {
        bool f = true;
        for (int j = i + k; j < n; j += k) {
            if (a[j] != a[j - k]) {
                f = false;
            }
        }
        if (k == 1) {
            f = false;
        }
        if (f) {
            int t = -1;
            for (int j = i; j < n; j += k) {
                if (b[j] != -1) {
                    if (t == -1) {
                        t = b[j];
                    } else if (t != b[j]) {
                        cout << "No\n";
                        return;
                    }
                }
            }
            if (t != -1) {
                for (int j = i; j < n; j += k) {
                    b[j] = t;
                }
            }
        } else {
            for (int j = i; j < n; j += k) {
                if (b[j] == -1) b[j] = a[j];
                if (b[j] != a[j]) {
                    cout << "No\n";
                    return;
                }
            }
        }
    }
    vector<int> ca(n + 1), cb(n + 1);
    for (int i = 0; i < k; i++) {
        ca[a[i]]++;
        if (b[i] != -1) {
            cb[b[i]]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (cb[i] > ca[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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