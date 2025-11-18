#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    bool f = true;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '0') {
            if (f) ans++;
        } else {
            if (!f) ans++;
            f = false;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}