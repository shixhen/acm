#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(n + 3);
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        int t = x / 4;
        cnt[1]++;
        cnt[t + 1]--;
        //cout << x << " " << t << "\n";
        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                if (j > t) {
                    cnt[j]++;
                    cnt[j + 1]--;
                }
                if (j * j != x && x / j > t) {
                    cnt[x / j]++;
                    cnt[x / j + 1]--;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        //cout << cnt[i] << " ";
        if (n - cnt[i] <= k) {
            ans = i;
        }
    }
    cout << ans << "\n";
    return;
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
