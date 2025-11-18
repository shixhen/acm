#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n < 15) {
        if (n == 1 || n == 2 || n == 0) {
            cout << n + 1 << '\n';
        } else {
            cout << 3 << '\n';
        }
    } else {
        int t = n / 15;
        t *= 3;
        int add = n % 15;
        add = min(2, add);
        cout << t  + 1 + add << '\n';
    }
    
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