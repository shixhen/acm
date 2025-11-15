#include <bits/stdc++.h>

using namespace std;

int a[705][705];
map<int, bool> mp;
void solve() {
    mp.clear();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n + 2; i++) {
        for (int j = 0; j <= m + 2; j++) {
            a[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[a[i][j]]) continue;
            if (a[i][j] == a[i - 1][j]) mp[a[i][j]] = true;
            if (a[i][j] == a[i][j - 1]) mp[a[i][j]] = true;
            if (a[i][j] == a[i + 1][j]) mp[a[i][j]] = true;
            if (a[i][j] == a[i][j + 1]) mp[a[i][j]] = true;
        }
    }
    int flag = 0;
    //cout << mp.size() << '\n';
    int ans = 0;
    for (auto &i: mp) {
        if (i.second) {
            flag = 1;
            ans += 2;
        } else ans++;
    }
    
    ans--;
    if (flag) ans--;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}