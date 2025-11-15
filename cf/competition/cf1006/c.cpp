#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int a = 0;
    int cnt = 1;
    for (int i = 0; i < n - 1; i++) {
        if ((i | x) == x) cout << i << " ", a |= i;
        else cnt++;
    }
    for (int i = 1; i <= cnt; i++) {
        if (((n - 1) | a) == x) cout << n - 1 << " ";
        else cout << (x ^ a) << " ";
    }
    cout << '\n';
    //cout << a << '\n';

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}