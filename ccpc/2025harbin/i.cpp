#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<map<int, int>> mp1(3), mp2(3);
    for (int i = 1, x, y, z; i <= n; i++) {
        cin >> x >> y >> z;
        mp1[0][x]++; mp1[1][y]++; mp1[2][z]++;
    }
    for (int i = 1, x, y, z; i <= m; i++) {
        cin >> x >> y >> z;
        mp2[0][x]++; mp2[1][y]++; mp2[2][z]++;
    }
    for (int i = 0; i < 3; i++) {
        for (auto &[k, v] : mp1[i]) {
            if ((mp2[i][k] & 1) != (v & 1)) {
                cout << "NO\n";
                return;
            }
        }
        for (auto &[k, v] : mp2[i]) {
            if ((mp1[i][k] & 1) != (v & 1)) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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