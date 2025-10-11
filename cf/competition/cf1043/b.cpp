#include <bits/stdc++.h>

using namespace std;

void solve() {
    unsigned long long n;
    vector<long long> ans;
    cin >> n;
    unsigned long long x = 11;
    while (x <= n) {
        if (n % x == 0) {
            ans.push_back(n / x);
        }
        x = (x - 1) * 10 + 1;
    }
    cout << ans.size() << "\n";
    if (ans.size()) {
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << " \n"[i == 0];
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}