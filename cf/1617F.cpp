#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    sort(a.begin(), a.end());
    int len = 0;
    int maxlen = 0;
    int r = -1;
    int cnt = 0;
    int now = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] != now) {
            if (cnt >= k && a[i] == a[i - 1] + 1) {
                len++;
                now = a[i];
                cnt = 1;
            }
            else {
                if (cnt >= k) len++;
                now = a[i];  
                if (maxlen < len) {
                    maxlen = len;
                    r = a[i - 1];
                }
                len = 0;
                cnt = 1;
            }
            
        } else {
            cnt++;
        }
    }
    if (maxlen < len) {
        maxlen = len;
        r = a[n - 1];
    }
    if (maxlen) {
        cout << r - maxlen + 1 << ' ' << r << '\n';
    } else cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}