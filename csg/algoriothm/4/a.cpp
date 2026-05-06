#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n + 1, vector<int>(n + 1));
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                cin >> a[i][j];
                a[i][j] += max(a[i - 1][j], a[i - 1][j - 1]);
                ans = max(ans, a[i][j]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}