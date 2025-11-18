#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        c[i] += c[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        int num = 1 - a[i];
        int j = i + 1;
        while (j <= n && a[j] == num) {
            j++;
            num = 1 - num;
        }
        for (int k = i; k < j; k++) {
            b[k] = j - 1;
        }
        i = j - 1;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        if ((r - l + 1) % 3 || (c[r] - c[l - 1]) % 3) {
            cout << -1 << "\n";
            continue;
        }
        int res = (r - l + 1) / 3;
        if (b[l] >= r) {
            res++;
        }
        cout << res << "\n";
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