#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    if (n < 3) {
        cout << "No";
        return 0;
    }
    if (s[n - 3] == 't'&& s[n - 2] == 'e' && s[n - 1] == 'a') {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}