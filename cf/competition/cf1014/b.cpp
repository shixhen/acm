#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            if (b[i] == '0') {
                cnt--;
            }
        } else {
            if (a[i] == '1') {
                cnt++;
            }
        }
    }
    if (cnt > 0) {
        cout << "NO\n";
        return;
    }
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (b[i] == '0') {
                cnt--;
            }
        } else {
            if (a[i] == '1') {
                cnt++;
            }
        }
    }
    if (cnt > 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}