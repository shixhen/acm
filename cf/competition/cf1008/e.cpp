#include <bits/stdc++.h>

using namespace std;

void solve() {
    cout << 0 << endl;
    cout.flush();
    int a1, a2;
    cin >> a1;
    int q2 = 0;
    while (a1 > 0) {
        q2 <<= 1;
        q2++;
        a1 >>= 1;
    }
    cout << q2 << endl;
    cout.flush();
    cin >> a2;
    int d = a2 - a1;
    
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