#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if ((n & 1) && s[0] == 'b') {
        cout << "No\n";
        return;
    }
    if (n & 1) {
        s[0] = 'a';
    }
    int cnta = 0, cntb = 0, cnti;
    for (auto &c : s) {
        if (c == 'a') {
            cnta++;
        } else if (c == 'b') {
            cntb++;
        }
    }
    //cout << cnta << " " << cntb << "\n";
    if (cnta > (n + 1) / 2 || cntb > n / 2) {
        cout << "No\n";
        return;
    }
    for (int i = (n & 1); i < n - 1; i += 2) {
        if (s[i] != '?' && s[i + 1] != '?' && s[i] == s[i + 1]) {
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