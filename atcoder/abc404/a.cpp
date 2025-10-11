#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string s;
    cin >> s;
    for (int i = 0; i < 26; i++) {
        if (s.find('a' + i) == -1) {
            cout << (char) ('a' + i);
            return 0;
        }
    }

    return 0;
}