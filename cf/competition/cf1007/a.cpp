#include <bits/stdc++.h>

using namespace std;
bool f[2000];
void solve() {
    int n;
    cin >> n;
    if (n % 3 == 1) cout << "Yes" << '\n';
    else cout << "No" << '\n';
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