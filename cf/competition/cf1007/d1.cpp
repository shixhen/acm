#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, l, r;
    cin >> n >> l >> r;
    string s = " ";
    char a;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        s += a;
    }
    if (l <= n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1') cnt++;
        }
        if (cnt % 2) cout << 1 << '\n';
        else cout << 0 << '\n';
        return;
    } else {
        while (l / 4 > n) {
            l /= 4;
        }
        if (l / 2 <= n) {
            int cnt = 0;
            for (int i = 1; i <= l / 2; i++) {
                if (s[i] == '1') cnt++;
            }
            if (cnt % 2) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else {
            if ((l / 2) % 2) cout << 0 << '\n';
            else {
                int cnt = 0;
                for (int i = 1; i <= l / 4; i++) {
                    if (s[i] == '1') cnt++;
                }
                if (cnt % 2) cout << 1 << '\n';
                else cout << 0 << '\n';
            }
        }
    }
    return;  
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}