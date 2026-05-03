#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    vector<long long> b;
    long long add = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int i = 1;
    while (i <= n && a[i] == 1) {
        add++;
        i++;
    }
    if (i == n + 1) {
        cout << n << "\n";
        return;
    }
    int j = n;
    while (j >= i && a[j] == 1) {
        add++;
        j--;
    }
    b.push_back(0);
    for (int k = i; k <= j; k++) {
        b.push_back(a[k]);
    }
    bool flag = false;
    long long sum = 1;
    for (int i = 1; i < b.size(); i++) {
        if (b[i] >= 2 * n) {
            flag = true;
            break;
        }
        sum = sum * b[i];
        if (sum >= 2 * n) {
            flag = true;
            break;
        }
    }
    if (flag) {
        long long ans = 1;
        for (int i = 1; i < b.size(); i++) {
            ans = ans * b[i] % mod;
        }
        cout << (ans + add) % mod << "\n";
        return;
    }
    vector<int> p;
    p.push_back(0);
    vector<long long> c(b.size());
    
    for (int i = 1; i < b.size(); i++) {
        c[i] = c[i - 1] + b[i];
    }
    for (int i = 1; i < b.size(); i++) {
        if (b[i] > 1) {
            p.push_back(i);
        }
    }
    vector<long long> dp(p.size());
    for (int i = 1; i < p.size(); i++) {
        long long temp = 1;
        dp[i] = dp[i - 1] + b[p[i]] + c[p[i] - 1] - c[p[i - 1]];
        for (int j = i - 1; j > 0; j--) {
            temp *= b[p[j]];
            dp[i] = max(dp[i], b[p[i]] * temp + dp[j - 1] + c[p[j] - 1] - c[p[j - 1]]);
        }
    }
    cout << (dp.back() + add) % mod << "\n";
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