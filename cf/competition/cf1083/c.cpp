#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    vector<int> vis(1000001);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        int t;
        for (int j = 0; j < m; j++) {
            cin >> t;
            a[i].push_back(t);
        }
        reverse(a[i].begin(), a[i].end());
        vector<int> cur;
        for (auto &x : a[i]) {
            if (!vis[x]) {
                vis[x] = 1;
                cur.push_back(x);
            }
        }
        a[i] = cur;
        for (auto &x : a[i]) {
            vis[x] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        int temp = 0;
        for (int j = 1; j < n - i; j++) {
            int k = 0;
            for (; k < min(a[j].size(), a[temp].size()); k++) {
                if (a[j][k] < a[temp][k]) {
                    temp = j;
                    break;
                } else if (a[j][k] > a[temp][k]) {
                    break;
                }
            }
            if (k == a[j].size()) {
                temp = j;
            }
        }
        swap(a[n - i - 1], a[temp]);
        if (a[temp].size() == 0) {
            continue;
        }
        for (int j = 0; j < a[n - i - 1].size(); j++) {
            if (!vis[a[n - i - 1][j]]) {
                vis[a[n - i - 1][j]] = 1;
                cout << a[n - i - 1][j] << " ";
            }
        }
        for (int j = 0; j < n - i; j++) {
            vector<int> cur;
            for (int k = 0; k < a[j].size(); k++) {
                if (!vis[a[j][k]]) {
                    cur.push_back(a[j][k]);
                }
            }
            a[j] = cur;
        }
    }
    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}