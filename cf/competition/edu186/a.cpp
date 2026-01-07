#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s.find("2025") == string::npos || s.find("2026") != string::npos) {
        cout << "0\n";
    } else {
        cout << "1\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }

    return 0;
}