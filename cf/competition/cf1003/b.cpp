#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            cout << "1" << "\n";
            return;
        }
    }
    cout << s.size() << "\n";
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}