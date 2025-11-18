#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt0 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cnt0++;
        }
    }
    int cnt = 0;
    for (int i = 0; i < cnt0; i++) {
        if (s[i] == '1') {
            cnt++;
        }
    }
    cout << cnt << "\n";
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