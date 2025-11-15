#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (s == string(n, '<') || s == string(n, '>')) {
        cout << n << "\n";
        return;
    }
    int l = 0, r = n - 1;
    while (s[l] == '<') {
        l++;
    }
    while (s[r] == '>') {
        r--;
    }
    if (l == r + 1) {
        cout << max(l, n - r - 1) << "\n";
        return;
    }
    if (l == r && s[l] == '*') {
        cout << max(l + 1, n - r) << "\n";
        return;
    }
    cout << "-1\n";
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
