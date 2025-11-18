#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a;
    cin >> n;
    n -= 3;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a == 1 && cnt > 0) {
            cout << "NO" << '\n';
            break;
        }
        if (a == 1) cnt = 2;
        else cnt--;
    }
    cout << "YES" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}