#include <bits/stdc++.h>

using namespace std;


constexpr long long mod = 1e8 + 7;

long long dp[3001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    dp[1] = 1;
    dp[0] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i * 2; j += 2) {
            //cout << (j - 1) / 2 << " " << (i * 2 - j - 1) / 2 << "\n";
            dp[i] += (dp[(j - 1) / 2] * dp[(i * 2 - j - 1) / 2]) % mod;
            dp[i] %= mod;
        }
    }
    cout << dp[n] << "\n";



    return 0;
}