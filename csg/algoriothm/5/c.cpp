#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, b;
    cin >> n >> b;
    vector<long long> a(n + 1, 0);
    a[1] = b;
    for(int i = 2; i <= n; i ++) {
        a[i] = 1LL * (a[i - 1] + 1) * (a[i - 1] + 1) % mod;
    }
    vector<long long> dp;
    for (int i = 1; i <= n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        if (it == dp.end()) {
            dp.push_back(a[i]);
        } else {
            *it = a[i];
        }
    }
    cout << dp.size() << "\n";
    return 0;
}