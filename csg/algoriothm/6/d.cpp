#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            swap(a[i].first, a[i].second);
        }
        sort(a.begin(), a.end());
        int ans = 0;
        int now = 0;
        for (int i = 0; i < n; i++) {
            now += a[i].second;
            ans = max(ans, now - a[i].first);
        }
        cout << ans << "\n";
    }


    return 0;
}