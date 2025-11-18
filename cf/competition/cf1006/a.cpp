#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    //cout << n * p << '\n';
    if (n * p < abs(k)) {
        cout << -1 << '\n';
        return;
    }
    int add = 0;
    if (k % p != 0) add = 1;
    cout << (abs(k) / p) + add << '\n';
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