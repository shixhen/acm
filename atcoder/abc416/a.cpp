#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    int l, r;
    string s;
    cin >> n >> l >> r;
    cin >> s;
    for (int i = l - 1; i <= r - 1; i++) {
        if (s[i] != 'o') {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";


    return 0;
}