#include <bits/stdc++.h>

using namespace std;



void solve() {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n + 1);
    vector<long long> dp(n + 1);
    string s;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        
    }
    long long res = a[0];
    for (int i = 1; i <= n; i++) {
        dp[i] = max(0ll, dp[i - 1]) + a[i];
        res = max(dp[i], res);
    }
    if (res > k) {
        vector<long long> dp2(n + 1);
        for (int i = 1; i <= n; i++) {
            //cout << "111" << endl;
            if (dp[i] < 0) continue;
            int j = i;
            long long temp = 0;
            while (j <= n and dp[j] >= 0) {
                temp += a[j];
                j++;
                
            }
            bool f = false;
            for (; i < j; i++) {
                f = true;
                if (s[i] == '0') {
                    a[i] = k - temp;
                    break;
                }
            }
            i = j - 1;
        }
        long long maxn = a[0];
            for (int i = 1; i <= n; i++) {
                dp2[i] = max(0ll, dp2[i - 1]) + a[i];
                maxn = max(dp2[i], maxn);
            }
            if (maxn != k) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
                for (int i = 1; i <= n; i++) {
                    cout << a[i] << ' ';
                }
                cout << '\n'; 
            }
    } else if (res < k) {

        vector<long long> dp2(n + 1);
        for (int i = 1; i <= n; i++) {
            //cout << "1112222" << endl;
            if (dp[i] < 0) continue;
            int j = i;
            long long temp = 0;
            while (j <= n and dp[j] >= 0) {
                temp += a[j];
                j++;
                
            }
            bool f = false;
            for (; i < j; i++) {
                f = true;
                if (s[i] == '0') {
                    a[i] = k - temp;
                    break;
                }
            }
            i = j - 1;
        }
        long long maxn = a[0];
            for (int i = 1; i <= n; i++) {
                dp2[i] = max(0ll, dp2[i - 1]) + a[i];
                maxn = max(dp2[i], maxn);
            }
            if (maxn != k) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
                for (int i = 1; i <= n; i++) {
                    cout << a[i] << ' ';
                }
                cout << '\n'; 
            }
    } else {
        cout << "Yes\n";
        for (int i = 1; i <= n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n'; 
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}