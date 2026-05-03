#include <bits/stdc++.h>

using namespace std;

constexpr long long inf = 1000000000000000000ll;

int ask(long long x) {
    cout << "? " << x << endl;
    int res;
    cin >> res;
    return res;
}

vector<vector<long long>> dp(200005, vector<long long>(61));


void init() {
    for (int i = 1; i <= 200000; i++) {
        for (int j = 1; j <= 60; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + 1;
            if (dp[i][j] > inf) {
                dp[i][j] = inf;
            }
        }
    }
}

void solve() {
    long long n, m;
    cin >> n >> m;
    if (m >= 60) {
        long long l = 0, r = n;
        while (l < r) {
            long long mid = (l + r + 1) >> 1;
            if (ask(mid) == 1) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        cout << "! " << l << endl;
        return;
    }
    //cout << 111111 << endl;
    // int cnt = 0;
    // while (dp[cnt].back() < n) {
    //     cnt++;
    //     for (int i = 1; i <= m; i++) {
    //         dp[cnt][i] = dp[cnt - 1][i] + dp[cnt - 1][i - 1] + 1;
    //         if (dp[cnt][i] > inf) {
    //             dp[cnt][i] = inf;
    //         }
    //     }
    // }
    //cout << dp.size() << endl;
    int cnt = 1;
    while (dp[cnt][m] < n) {
        //cout << cnt << " " << m << " " << dp[cnt][m] << endl;
        cnt++;
        
    }
    // cout << cnt << endl;
    long long l = 0, r = n;
    while (l < r) {
        //cout << cnt << " " << m << endl;
        long long pre = dp[cnt - 1][m - 1];
        //cout << pre << endl;
        long long mid = l + pre + 1;
        if (mid > r) {
            mid = r;
        }
        if (ask(mid)) {
            r = mid - 1;
            m--;
        } else {
            l = mid;
            //cout << l << " " << r << endl;
        }
        cnt--;
    }
    cout << "! " << l << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}