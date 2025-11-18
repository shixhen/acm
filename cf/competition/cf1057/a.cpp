#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(105);
    int ans = 0;
    for (auto &i : a) {
        cin >> i;
        if (cnt[i] == 0) ans++;
        cnt[i]++;
    }
    cout << ans << "\n";
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