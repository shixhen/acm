#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 1 << (31 - __builtin_clz(n))) {
        cout << -1 << "\n";
        return;
    }
    vector<int> ans(n + 1);
    ans[n] = 1;
    
    for (int i = 2; i < n; ++i) {
        ans[i] = i ^ 1;
    }
    
    if (n % 2 == 0) {
        ans[1] = n;
    } else {
        ans[1] = n - 1;
    }
    int t = n - (1 << (31 - __builtin_clz(n)));
    swap(ans[t], ans[1]);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}