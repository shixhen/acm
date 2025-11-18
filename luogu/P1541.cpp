#include <bits/stdc++.h>

using namespace std;

struct node {
    int v, w, x, y, z;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    node s;
    int x;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        if (x == 1) {
            s.w++;
        } else if (x == 2) {
            s.x++;
        } else if (x == 3) {
            s.y++;
        } else if (x == 4) {
            s.z++;
        }
    }
    vector<vector<node>> dp(n + 1, vector<node>());
    s.v = a[1];
    dp[1].push_back(s);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (auto& j: dp[i]) {
            if (i + 1 <= n and j.w > 0) {
                node t = j;
                t.v += a[i + 1];
                ans = max(ans, t.v);
                t.w--;
                dp[i + 1].push_back(t);
            }
            if (i + 2 <= n and j.x > 0) {
                node t = j;
                t.v += a[i + 2];
                ans = max(ans, t.v);
                t.x--;
                dp[i + 2].push_back(t);
            }
            if (i + 3 <= n and j.y > 0) {
                node t = j;
                t.v += a[i + 3];
                ans = max(ans, t.v);
                t.y--;
                dp[i + 3].push_back(t);
            }
            if (i + 4 <= n and j.z > 0) {
                node t = j;
                t.v += a[i + 4];
                ans = max(ans, t.v);
                t.z--;
                dp[i + 4].push_back(t);
            }
        }
        dp[i].clear();
    }
    cout << ans << '\n';
    return 0;
}