#include <bits/stdc++.h>

using namespace std;


int a[2005][2005];
vector<int> g[2005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cin >> a[i][j];
            a[j][i] = a[i][j];
            if (a[i][j] == (i ^ j)) {
                g[i].push_back(j);
            }
            if (a[i][j] == 0) {
                v.push_back(i);
                v.push_back(j);
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (auto &x : g[i]) {
            bool f = true;
            for (auto &k : v) {
                if (k == i || k == x) continue;
                if ((a[i][k] ^ a[k][x] ^ a[i][x]) == k) {
                    f = false;
                    break;
                }
            }
            if (f) {
                cout << i << " " << x << "\n";
                cnt++;
                if (cnt == n - 1) return 0;
            }
        }
    }
    return 0;
}