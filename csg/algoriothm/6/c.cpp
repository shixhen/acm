#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            swap(a[i].first, a[i].second);
        }
        sort(a.begin(), a.end());
        int ans = 0;
        int last = 0;
        for (int i = 0; i < n; i++) {
            if (a[i].second >= last) {
                ans++;
                last = a[i].first;
            }
        }
        cout << ans << "\n";
    }

}