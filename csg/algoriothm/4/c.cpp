#include <bits/stdc++.h>

using namespace std;

struct v {
    int a, b, c;
};
int n;
vector<v> a;
vector<int> dp;

int dfs(int i) {
    if (dp[i]) return dp[i];
    int res = 0;
    for (int j = 0; j < 3 * n; j++) {
        if ((a[i].b > a[j].b && a[i].c > a[j].c) || (a[i].b > a[j].c && a[i].c > a[j].b)) {
            res = max(res, dfs(j));
        }
    }
    return dp[i] = res + a[i].a;
}
int main() {
    while (cin >> n) {
        a.resize(n * 3);
        dp.assign(n * 3, 0);
        for (int i = 0; i < n * 3; i += 3) {
            cin >> a[i].a >> a[i].b >> a[i].c;
            a[i + 1] = a[i];
            a[i + 2] = a[i];
            swap(a[i + 1].a, a[i + 1].b);
            swap(a[i + 2].a, a[i + 2].c);
        }
        int ans = 0;
        for (int i = 0; i < n * 3; i++) {
            dfs(i);
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}