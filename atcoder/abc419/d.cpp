#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> a(s.size() + 2);
    int l, r;
    for (int i = 1; i <= m; i++) {
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }
    for (int i = 1; i <= s.size(); i++) {
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= s.size(); i++) {
        if (a[i] % 2) {
            cout << t[i - 1];
        } else {
            cout << s[i - 1];
        }
    }

    return 0;
}