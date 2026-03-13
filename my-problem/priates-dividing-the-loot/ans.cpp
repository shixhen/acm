#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << m - ((n - 1) >> 1);
        for (int i = 0; i < n - 1; i++) {
            cout << " " << (i & 1);
        }
        cout << "\n";
    }
    return 0;
}