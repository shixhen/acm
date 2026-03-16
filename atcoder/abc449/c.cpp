#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (i - l >= 0) {
            cnt[s[i - l] - 'a']++;
        }
        if (i - r - 1 >= 0) {
            cnt[s[i - r - 1] - 'a']--;
        }
        ans += cnt[s[i] - 'a'];
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}