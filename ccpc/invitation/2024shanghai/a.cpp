#include <bits/stdc++.h>

using namespace std;


int ans[105][105];

int n, m;

bool is_in(int x, int y) {
    if (x < 0 || x > n || y < 0 || y > m) {
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int x = -n; x <= n; x++) {
                for (int y = -m; y <= m; y++) {
                    if (x == 0 && y == 0) {
                        continue;
                    }
                    if (is_in(i + x, j + y) && is_in(i + y, j - x) && is_in(i + x + y, j + y - x)) {
                        ans[i][j]++;
                    }
                }
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}