#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (auto &i: a) {
        cin >> i;
    }
    for (auto &i: b) {
        cin >> i;
    }
    int num = 0;
    if (a[n - 1] != b[n - 1]) {
        cout << "No\n";
        return;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] != b[i]) {
            if ((a[i] ^ b[i]) != num && (a[i] ^ b[i]) != a[i + 1]) {
                cout << "No\n";
                return;
            }
            num = b[i];
        } else {
            num = a[i];
        }
    }
    cout << "Yes\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}