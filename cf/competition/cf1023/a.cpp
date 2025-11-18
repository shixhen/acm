#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    bool flag = false;
    int j = 1;
    int maxn = a[0];
    for (; j < n; j++) {
        if (a[j] != a[j - 1]) {
            flag = true;
        }
        maxn = max(maxn, a[j]);
    }
    if (flag) {
        cout << "Yes\n";
        for (auto &i: a) {
            if (i == maxn) {
                cout << "2 ";
            } else cout << "1 ";
        }
        cout << '\n';
    } else {
        cout << "No\n";
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}