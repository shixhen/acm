#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int num = 0;
    char ch = '0';
    for (int i = 0; i < n; i++) {
        if (ch != s[i]) {
            num++;
            ch = '1' + '0' - ch;
        }
    }
    cout << num << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}