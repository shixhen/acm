#include <bits/stdc++.h>

using namespace std;

constexpr long long mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        long long n;
        cin >> n;
        if (n < 5) {
            cout << n << "\n";
            continue;
        }
        vector<long long> ans;
        int p = 2;
        while (n >= p) {
            ans.push_back(p);
            n -= p;
            p++;
        }
        if (n >= ans.size()) {
            ans[0] += n;
        } else {
            for (int i = ans.size() - 1; i >= ans.size() - n; i--) {
                ans[i]++;
            }
        }
        long long x = 1;
        for (auto &v : ans) {
            x = (x * v) % mod;
        }
        cout << x << "\n";
    }
    
    return 0;
}