#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    int i = 0;
    while (a >= 0) {
        if (a + 1 == b) {
            cout << "Yes" << "\n";
            return;
        }
        a -= 9;
    }
    cout << "No" << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}