#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> count_digits(ll n) {
    if (n == 0) {
        return vector<ll>(10, 0);
    }
    vector<ll> digits;
    while (n) {
        digits.push_back(n % 10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());
    int len = digits.size();
    vector<vector<vector<vector<ll>>>> dp(len + 1, vector<vector<vector<ll>>>(2, vector<vector<ll>>(2, vector<ll>(10, -1))));
    function<vector<ll>(int, bool, bool)> dfs = [&] (int pos, bool tight, bool lead) -> vector<ll> {
        if (pos == len) {
            return vector<ll>(10, 0);
        }
        auto &memo = dp[pos][tight][lead];
        if (memo[0] != -1) return memo;     

        vector<ll> res(10, 0);
        int limit = tight ? digits[pos] : 9;
        bool next_lead;
        for (int i = 0; i <= limit; ++i) {
            next_lead = lead && (i == 0);
            vector<ll> next = dfs(pos + 1, tight && (i == limit), next_lead);
            for (int j = 0; j < 10; ++j) {
                res[j] += next[j];
            }
            if (!next_lead) {
                res[i]++;
            }
        }
        return memo = res;
    };

    return dfs(0, true, true);
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long long a, b;
    cin >> a >> b;
    auto count_a = count_digits(a - 1);
    auto count_b = count_digits(b);
    for (int i = 0; i < 10; ++i) {
        cout << count_b[i] - count_a[i] << " \n"[i == 9];
    }
    return 0;
}