#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    if (s[n - 1] == '0' && s[n - 2] == '0') {
        cout << "Yes\n";
        return;
    }
    if (s.size() == 3) {
        cout << "No\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (i == n - 3 && cnt < 0) {
            cout << "No\n";
            return;
        }
        if (i == n - 2) {
            if (cnt < 0 || (cnt == 0 && s[i] == '0')) {
                cout << "No\n";
                return;
            } else {
                cout << "Yes\n";
                return;
            }
        }
        if (s[i] == '0') cnt--;
        else {
            cnt = max(cnt, 0);
            cnt++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}