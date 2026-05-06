#include <bits/stdc++.h>

using namespace std;

void solve() { 
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1 || s[0] == s[n - 1]) {
        cout << "0\n";
        return;
    }
    int i = 0;
    while (i < n) {
        if (s[i] == s[(i + n - 1) % n]) {
            cout << i << "\n";
            return;
        }
        i++;
    }
    cout << "-1\n";
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