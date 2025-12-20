#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    if (k % 2) {
        for (int i = 1; i <= k; i++) {
            cout << n << " ";
        }
        cout << "\n";
        return;
    }
    vector<long long> a(k, 0);
    int p = 0;
    for (int i = 32; i >= 0; i--) {
        if (n & (1LL << i)) {
            if (p >= k) {
                for (int j = 1; j < k; j++) {
                    a[j] += (1LL << i);
                }
                continue;
            }
            for (int j = 0; j < k; j++) {
                if (j != p) {
                    a[j] += (1LL << i);
                }
            }
            p++;
        } else {
            for (int j = 0; j < ((p >> 1) << 1); j++) {
                a[j] += (1LL << i);
            }
        }
    }
    for (auto x : a) {
        cout << x << " ";
    }
    cout << "\n";
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}