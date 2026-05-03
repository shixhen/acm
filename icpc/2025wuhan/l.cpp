#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 1;
    for (int i = 0; i < (int) a.size() - 1; i++) {
        int k = i;
        for (int j = i; j >= 0; j--) {
            while (k < (int) a.size() && a[k] + a[j] < 2 * a[i]) {
                k++;
            }
            if (k == (int) a.size()) {
                break;
            }
            if (a[k] + a[j] != 2 * a[i]) {
                continue;
            }
            while (k + 1 < (int) a.size() && a[k + 1] == a[k]) {
                k++;
            }
            //cout << a[i] << " " << a[j] << " " << a[k] << "\n";
            int minn = i - j;
            int maxn = k - i;
            if (minn >= maxn) {
                ans = max(ans, maxn * 2 + 1);
            } else {
                ans = max(ans, minn * 2 + 2);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}