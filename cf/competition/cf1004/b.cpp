#include <bits/stdc++.h>

using namespace std;

int num[1005];
void solve() {
    int n, _;
    cin >> n;
    for (int i = 1; i <= n; i++) num[i] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> _;
        num[_]++;
    }
    for (int i = 1; i < n; i++) {
        if (num[i] == 0) continue;
        if (num[i] == 1) {
            cout << "No" << "\n";
            return;
        }
        if (num[i] >= 2) {
            num[i + 1] += num[i] - 2;
        }
    }
    if (num[n] % 2 == 1) {
        cout << "No" << "\n";
        return;
    }
    cout << "Yes" << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}