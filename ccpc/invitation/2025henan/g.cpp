#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "1 2\n";
        return;    
    } else if (n == 3) {
        cout << "1 2\n2 3\n";
        return;
    } else if (n == 4) {
        cout << "-1\n";
        return;
    }
    int add = n - (n - 3) / 2;
    for (int i = 1; i < add; i++) {
        cout << i << " " << i + 1 << "\n";
    }
    for (int i = 1; i <= n - add; i++) {
        cout << i + 1 << " " << i + add << "\n";
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}