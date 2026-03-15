#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, p, m;
    cin >> n >> k >> p >> m;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    int ans = 0;
    while (m > 0) {
        int idx = 1;
        for (int i = 1; i <= k; i++) {
            if (a[idx].first > a[i].first) {
                idx = i;
            }
            if (a[i].second == p) {
                idx = i;
                break;
            }
        }
        if (a[idx].second == p) {
            if (a[idx].first <= m) {
                m -= a[idx].first;
                for (int i = idx; i < n; i++) {
                    swap(a[i], a[i + 1]);
                }
                ans++;
            } else {
                break;
            }
        } else {
            if (a[idx].first <= m) {
                m -= a[idx].first;
                for (int i = idx; i < n; i++) {
                    swap(a[i], a[i + 1]);
                }
            } else {
                break;
            }
        }
    }
    cout << ans << "\n";

    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}