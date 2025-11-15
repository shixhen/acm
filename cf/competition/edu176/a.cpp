#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    if (n % 2) {
        n -= k;
        ans++;
    }
    ans += n / (k - 1);
    if (n % (k - 1)) ans++;
    cout << ans << '\n';
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