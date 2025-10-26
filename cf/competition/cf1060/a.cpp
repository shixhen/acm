#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (cnt) {
                cnt = k - 1;
            } else {
                ans++;
                cnt = k - 1;
            }
        } else {
            if (cnt) {
                cnt--;
            }
        }
    }
    cout << ans << "\n";
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