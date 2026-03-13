#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int t = 0;
    int ansmx = 0;
    for (int i = 1; i < n - 1; i++) {
        if (s[i - 1] == '1' && s[i + 1] == '1') {
            s[i] = '1';
        }
    }
    for (auto &x : s) {
        if (x == '1') {
            ansmx++;
        }
    }
    int ansm = ansmx;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            t++;
        } else {
            ansm -= max(0, (t + 1) / 2 - 1);
            t = 0;
        }
    }
    ansm -= max(0, (t + 1) / 2 - 1);
    
    cout << ansm << " " << ansmx << "\n";
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