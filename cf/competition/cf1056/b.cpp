#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<char>> g(n + 1, vector<char>(n + 1));
    if (k == n * n - 1) {
        cout << "No\n";
        return;
    }
    if (k == n * n) {
        cout << "Yes\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << 'L';
            }
            cout << "\n";
        }
        return;
    }
    if (k == 0) {
        cout << "Yes\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << (j == n ? 'L' : 'R');
            }
            cout << "\n";
        }
        return;
    }
    int i = 1, j = 1;
    int cnt = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            g[i][j] = 'U';
            cnt++;
            if (cnt == k) {
                break;
            }
        }
        if (cnt == k) {
            break;
        }
    }
    if (j < n) {
        g[i][n] = 'D';
    }
    j++;
    for (; j < n; j++) {
        g[i][j] = 'R';
    }
    if (i == n) {
        g[i][n] = 'L';
    }
    i++;
    for (; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            g[i][j] = 'R';
            if (j == n) {
                g[i][j] ='L';
            }
        }
    }
    
    cout << "Yes\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << g[i][j];
        }
        cout << "\n";
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