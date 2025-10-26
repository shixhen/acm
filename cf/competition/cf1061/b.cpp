#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> a(q);
    bool f = true;
    for (auto &i : s) {
        if (i == 'B') {
            f = false;
            break;
        }
    }
    for (auto &i : a) cin >> i;
    for (auto &x : a) {
        if (f) {
            cout << x << "\n";
            continue;
        }
        int pos = 0;
        int t = 0;
        while (x > 0) {
            t++;
            if (s[pos] == 'A') {
                x--;
            } else {
                x >>= 1;
            }
            pos++;
            pos %= n;
        }
        cout << t << "\n";
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
