#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<char> s(n + 1);
    string str;
    cin >> str;
    if (k >= n) {
        cout << string(n, '-') << "\n";
        return;
    }
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (auto &c : str) {
        if (c == '0') cnt0++;
        else if (c == '1') cnt1++;
        else cnt2++;
    }
    for (int i = 1; i <= cnt0; i++) {
        s[i]= '-';
    }
    for (int i = n; i >= n - cnt1 + 1; i--) {
        s[i] = '-';
    }
    int j = cnt0 + 1;
    int cnt22 = cnt2;
    while (cnt2--) {
        s[j++] = '?';
        if (j > n || s[j] == '-') break;
    }
    j = n - cnt1;
    while (cnt22--) {
        s[j--] = '?';
        if (j <= 0 || s[j] == '-') break;
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == '?') cout << s[i];
        else if (s[i] == '-') cout << s[i];
        else cout << '+';
    }
    cout << "\n";
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