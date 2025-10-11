#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    long long n, x, y, z;
    while (t--) {
        cin >> n >> x >> y >> z;
        vector<int> a(n + 1);
        vector<long long> cnt(n + 3);
        int xx;
        for (int i = 0; i < n; i++) {
            cin >> xx;
            a[xx]++;
        }
        for (int i = 0; i <= n; i++) {
            cnt[1]++;
            cnt[a[i] + 1]--;
        }
        for (int i = 1; i <= n; i++) {
            cnt[i] += cnt[i - 1];
        }
        //cnt[i] 是 数量 大于等于i 的数字个数
        long long ans = 0;
        ans += cnt[1] * x;
        for (int i = 2; i <= n; i++) {
            ans += max(cnt[i] * y, (cnt[i] - 1) * x + z);
        }
        cout << ans << "\n";
    }
    return 0;
}