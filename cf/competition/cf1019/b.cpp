#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    int f = 0;
    int l = 0;
    int f2 = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (l == 0) ans++;
            if (l == 0 && cnt1) f2 = 1;
            cnt1++;
            l = 1;
        } else if (s[i] == '0') {
            if (l == 1) f = 1;
            cnt0++;
            if (l == 1) ans++;
            l = 0;
        }
    }
    cout << ans + n - f - f2 << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}