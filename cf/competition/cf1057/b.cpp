#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    vector<int> cnt(38);
    int j = 1;
    while (x) {
        if (x & 1) cnt[j]++;
        x >>= 1;
        j++;
    }
    j = 1;
    while (y) {
        if (y & 1) cnt[j]++;
        y >>= 1;
        j++;
    }
    j = 1;
    while (z) {
        if (z & 1) cnt[j]++;
        z >>= 1;
        j++;
    }
    for (int i = 1; i <= 31; i++) {
        if (cnt[i] == 2) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}