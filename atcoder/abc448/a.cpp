#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (a < x) {
            x = a;
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}