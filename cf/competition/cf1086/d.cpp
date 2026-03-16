#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            g[i][j] = s[j - 1] - '0';
        }
    }

    for (int i = 1; i <= n; i++) {
        if (g[i][i] == 0) {
            cout << "NO\n";
            return;
        }
        for (int j = i + 1; j <= n; j++) {
            if (g[i][j] && g[j][i]) {
                cout << "NO\n";
                return;
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (g[i][k] && g[k][j] && !g[i][j]) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || !g[i][j]) {
                continue;
            }
            bool flag = true;
            for (int k = 1; k <= n; k++) {
                if (k != i && k != j && g[i][k] && g[k][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans.push_back({i, j});
            }
        }
    }

    if (ans.size() != n - 1) {
        cout << "NO\n";
        return;
    }

    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);

    auto find = [&](auto&& self, int x) -> int {
        if (p[x] == x) {
            return x;
        }
        return p[x] = self(self, p[x]);
    };

    for (auto [u, v] : ans) {
        int fu = find(find, u);
        int fv = find(find, v);
        if (fu != fv) {
            p[fu] = fv;
        }
    }

    int root = find(find, 1);
    for (int i = 2; i <= n; i++) {
        if (find(find, i) != root) {
            cout << "NO\n";
            return;
        }
    }

    vector<vector<int>> c(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        c[i][i] = 1;
    }
    for (auto [u, v] : ans) {
        c[u][v] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                c[i][j] = max(c[i][j], c[i][k] & c[k][j]);
            }
        }
    }

    if (c != g) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (auto [x, y] : ans) {
        cout << x << " " << y << "\n";
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}