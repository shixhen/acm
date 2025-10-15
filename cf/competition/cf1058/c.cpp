#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int x = __builtin_ctz(n);
    string s(x, '0');
    string t;
    int n2 = n;
    while (n2) {
        if (n2 & 1) t.push_back('1');
        else t.push_back('0');
        n2 >>= 1;
    }
    reverse(t.begin(), t.end());
    s += t;
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            cout << "No\n";
            return;
        }
    }
    if (s.size() % 2 && s[s.size() / 2] == '1') {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}