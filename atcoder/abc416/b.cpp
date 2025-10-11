#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    bool f = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#') {
            cout << '#';
            f = true;
        } else if (f) {
            cout << 'o';
            f = false;
        } else {
            cout << '.';
        }
    }

    return 0;
}