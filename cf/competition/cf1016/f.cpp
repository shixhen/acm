#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &i: a) cin >> i;
    vector<bool> f(n);
    string s;
    int num = 0;
    int temp = 0;
    while (m--) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> s;
            if (s == a[i]) {
                if (!f[i]) num++;
                cnt++;
                f[i] = true;
            }
        }
        temp = max(temp, cnt);
    }
    if (num != n) cout << -1 << '\n';
    else {
        cout << 3 * n - 2 * temp << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}