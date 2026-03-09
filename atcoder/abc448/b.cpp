#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> c(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        ans += min(c[a], b);
        c[a] -= min(c[a], b);
    }
    cout << ans << "\n";
    return 0;
}