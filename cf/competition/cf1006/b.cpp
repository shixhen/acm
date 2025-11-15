#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    char ch;
    int cnt1 = 0;
    int cnt2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ch;
        if (ch == '-') cnt1++;
        if (ch == '_') cnt2++;
    }
    int cnt3 = cnt1 / 2;
    long long ans = (long long) cnt3 * cnt2 * (cnt1 - cnt3);
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