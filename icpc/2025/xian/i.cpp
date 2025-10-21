#include <bits/stdc++.h>

using namespace std;


int a[2005][2005];
vector<int> g[2005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            cin >> a[i][j];
            a[j][i] = a[i][j];
            if (a[i][j] == (i ^ j)) {
                g[i].push_back(j);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (auto &x : g[i]) {
            cout << "Checking " << i << " " << x << "\n";
            bool f = true;
            for (int k = 1; k <= n; k++) {
                if (k == i || k == x) continue;
                if ((a[i][k] ^ a[k][x] ^ a[i][x]) == k) {
                    f = false;
                    break;
                }
            }
            if (f) {
                cout << i << " " << x << "\n";
            }
        }
    }
    return 0;
}