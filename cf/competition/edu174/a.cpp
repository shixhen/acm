#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a;
    cin >> n;
    n -= 2;
    int cnt = 0;
    int flag = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a == 1 && cnt > 0 && cnt != 2) {
            flag = 1;
        }
        if (a == 1) cnt = 2;
        else cnt--;
    }
    if (flag) cout << "NO" << '\n';
    else cout << "YES" << '\n';
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