#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (k > max(m, n)) {
        cout << -1 << "\n";
        return;
    }
    if (k < abs(m - n)) {
        cout << -1 << "\n";
        return;
    }
  
    string s = "";
    int cnt1 = 0;
    int cnt0 = 0;
    if (m > n) {
        for (int i = 1; i <= k; i++) {
            s += '1';
        }
        cnt1 = k;
        while (cnt0 < n || cnt1 < m) {
            if (cnt0 < n) {
                cnt0++;
                s += '0';
            }
            if (cnt1 < m) {
                cnt1++;
                s += '1';
            }
        }
    } else {
        for (int i = 1; i <= k; i++) {
            s += '0';
        }
        cnt0 = k;
        while (cnt0 < n || cnt1 < m) {
            if (cnt1 < m) {
                cnt1++;
                s += '1';
            }
            if (cnt0 < n) {
                cnt0++;
                s += '0';
            }
        }
    }
    cout << s << "\n";
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}