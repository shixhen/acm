#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> ans(n + 1, vector<int>(n + 1, -1));
    vector<vector<int>> wg(n + 1);
    vector<set<int>> lg(n + 1);
    for (int i = 1; i < n; i++) {
        string s;
        cin >> s;
        for (int j = i + 1; j <= n; j++) {
            if (s[j - i - 1] == '1') {
                wg[i].push_back(j);
                lg[j].insert(i);
                ans[i][j] = 0;
            } else {
                wg[j].push_back(i);
                lg[i].insert(j);
                ans[j][i] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        vector<int> t2;
        t2.push_back(i);
        unordered_set<int> all;
        for (auto &x : wg[i]) {
            all.insert(x);
        }
        for (int k = 1; ; k++) {
            set<int> temp;
            for (auto x : t2) {
                for (auto y : wg[x]) {
                    if (!all.count(y)) {
                        temp.insert(y);
                        ans[i][y] = k;
                        //cout << i << " " << y << " " << k << "\n";
                    }
                }
            }
            if (temp.size() == 0) {
                break;
            }
            t2.clear();
            for (auto x : temp) {
                all.insert(x);
                t2.push_back(x);
            }
            temp.clear();
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << ans[x][y] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}