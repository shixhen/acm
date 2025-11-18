#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '1' + s + '1';
    vector<int> a;
    vector<int> ans(n + 1);
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            if (s[i - 1] != '0' && s[i + 1] != '0') {
                cout << "No\n";
                return;
            }
            if (s[i - 1] == '1') {
                num = i;
            }
            if (s[i + 1] == '1') {
                ans[i] = num;
            } else {
                ans[i] = i + 1;
            }
        } else {
            ans[i] = i;
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) { solve(); }
    return 0;
}