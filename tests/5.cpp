#include <bits/stdc++.h>

using namespace std;



struct seg_tree {
    
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> ans(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i < n; i++) {
        string s;
        cin >> s;
        for (int j = i + 1; j <= n; j++) {
            if (s[j - i - 1] == '1') {
                g[i][j] = 1;
                ans[i][j] = 0;
            } else {
                g[j][i] = 1;
                ans[j][i] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        queue<int> win;
        set<int> lose;
        for (int j = 1; j <= n; j++) {
            if (g[i][j]) {
                win.push(j);
            } else if (i != j) {
                lose.insert(j);
            }
        }
        while (!win.empty()) {
            int cur = win.front();
            win.pop();
            for (auto it = lose.begin(); it != lose.end(); ) {
                if (g[cur][*it]) {
                    ans[i][*it] = ans[i][cur] + 1;
                    win.push(*it);
                    it = lose.erase(it);
                } else {
                    ++it;
                }
            }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << ans[x][y] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}