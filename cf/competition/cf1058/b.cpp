#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<int> ans(n + 1);
    ans[1] = 1;
    int p = 2;
    for (int i = 2; i <= n; i++) {
        int x = b[i] - b[i - 1];
        if (i - x <= 0) {
            ans[i] = p++;
        } else {
            ans[i] = ans[i - x];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}