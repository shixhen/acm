#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    int ans;
    while (t--) {
        ans = 0;
        int n;
        cin >> n;
        vector<int> old(n);
        vector<int> now(n);
        for (int i = 0; i < n; i++) {
            swap(old, now);
            for (int j = 0; j <= i; j++) {
                cin >> now[j];
            }
            now[0] += old[0];
            if (i >= 1) {
                now[i] += old[i - 1];
            }
            for (int j = 1; j < i; j++) {
                now[j] += max(old[j - 1], old[j]);
            }
            if (i == n - 1) {
                for (int j = 0; j < n; j++) {
                    ans = max(ans, now[j]);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}