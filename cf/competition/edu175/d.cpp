#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1);
    int _;
    const int mod = 998244353;
    for (int i = 2; i <= n; i++) {
        cin >> _;
        a[_].push_back(i);
    }
    vector<int> old;
    vector<int> now;
    old.push_back(1);
    long long ans = 0;
    long long temp = 1;
    while(old.size()) {
        swap(old, now);
        old.clear();
        for (int i = 0; i < now.size(); i++) {
            int cur = now[i];
            for (int j = 0; j < a[cur].size(); j++) {
                old.push_back(a[cur][j]);
            }
        }
        if (old.empty()) break;
        if (now.size() == 1 && now[0] == 1) now.push_back(1);
        ans += (long long) old.size() * (long long) (now.size() - 1) *(long long) temp;
        ans %= mod;
        temp = temp * (now.size() - 1);
        temp %= mod;
    }
    cout << (ans + 1) % mod << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}