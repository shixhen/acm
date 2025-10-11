#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int temp = 0;
    int maxn = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            temp++;
        } else {
            maxn = max(maxn, temp);
            temp = 0;
        }
    }
    maxn = max(maxn, temp);
    if (maxn >= k) {
        cout << "No\n";
        return;
    }
    int p = n;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            ans[i] = p--;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ans[i] = p--;
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    return;
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
