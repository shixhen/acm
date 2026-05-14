#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        auto check = [&] (int x) -> bool {
            int cnt = 1;
            int temp = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] > x) return false;
                if (temp + a[i] > x) {
                    cnt++;
                    temp = 0;
                }
                temp += a[i];
            }
            return cnt <= k;
        };
        int l = 0, r = 1e9;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        vector<int> ans;
        int cnt = 0;
        for (int i = (int) a.size() - 1, temp = 0; i >= 0; i--) {
            if (temp + a[i] > l || i < k - cnt - 1) {
                ans.push_back(-1);
                temp = 0;
                cnt++;
            }
            temp += a[i];
            ans.push_back(a[i]);
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < (int) ans.size(); i++) {
            if (ans[i] == -1) cout << "/ ";
            else cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}