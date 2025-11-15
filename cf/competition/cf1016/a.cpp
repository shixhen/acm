#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 2) {
        cout << "Yes\n";
    } else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}