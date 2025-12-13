#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> vis(n + 1, 0);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        int x = i;
        long long cnt = 0;
        while (!vis[x]) {
            vis[x] = 1;
            x = a[x];
            cnt++;
        }
        ans += (cnt * (cnt - 1ll)) / 2ll;
    }
    cout << ans << "\n";

    return 0;
}