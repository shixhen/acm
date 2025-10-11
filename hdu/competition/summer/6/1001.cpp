#include <bits/stdc++.h>


using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int cnt0 = 0;
        int cntz = 0;
        long long maxn = INT_MAX;
        long long minn = INT_MAX;
        vector<long long> a(n);
        for (auto &i: a) {
            cin >> i;
            if (i < 0) {
                cntz++;
                maxn = min(maxn, -i);
            } else if (i == 0) {
                cnt0++;
            } else {
                minn = min(minn, i);
            }
        }
        if (cnt0) {
            cout << cnt0 << "\n";
            continue;
        }
        long long ans = 0;
        if (cntz % 2) {
            ans += min(maxn + 1, minn + 1);
        }
        cout << ans << "\n";
        

    }
    return 0;
}