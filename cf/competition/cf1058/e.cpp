#include <bits/stdc++.h>

using namespace std;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<vector<int>> ans(n, vector<int>(m, inf));
    for (auto &s : a) cin >> s;
    if (n <= m) {
        for (int i = 0; i < n; i++) {
            vector<int> temp(m, inf);
            for (int j = n - 1; j > i; j--) {
                int last = -1;
                for (int k = 0; k < m; k++) {
                    if (a[i][k] == a[j][k] && a[i][k] == '1') {
                        if (last != -1) {
                            for (int t = last; t <= k; t++) {
                                temp[t] = min(temp[t], (k - last + 1) * (j - i + 1));
                            }
                        }
                        last = k;
                    }
                }
                for (int k = 0; k < m; k++) {
                    ans[j][k] = min(ans[j][k], temp[k]);
                }
            }
            for (int k = 0; k < m; k++) {
                ans[i][k] = min(ans[i][k], temp[k]);
            }
        }
    } else {
        for (int i = 0; i < m; i++) {
            vector<int> temp(n, inf);
            for (int j = m - 1; j > i; j--) {
                int last = -1;
                for (int k = 0; k < n; k++) {
                    if (a[k][i] == a[k][j] && a[k][i] == '1') {
                        if (last != -1) {
                            for (int t = last; t <= k; t++) {
                                temp[t] = min(temp[t], (k - last + 1) * (j - i + 1));
                            }
                        }
                        last = k;
                    }
                }
                for (int k = 0; k < n; k++) {
                    ans[k][j] = min(ans[k][j], temp[k]);
                }
            }
            for (int k = 0; k < n; k++) {
                ans[k][i] = min(ans[k][i], temp[k]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (ans[i][j] == inf ? 0 : ans[i][j]) << " \n"[j == m - 1];
        }
    }
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