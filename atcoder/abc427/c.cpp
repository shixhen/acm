#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int s = (1 << n) - 1;
    vector<pair<int, int>> edges(m);
    for (auto &[u, v] : edges) {
        cin >> u >> v;
    }
    int ans = 0x3f3f3f3f;
    for (int i = s;; i = (i - 1) & s) {
        int temp = 0;
        for (auto [u, v] : edges) {
            if (((1 << (u - 1)) & i) && ((1 << (v - 1)) & i)) {
                temp++;
            } else if (!((1 << (u - 1)) & i) && !((1 << (v - 1)) & i)) {
                temp++;
            }
        }
        ans = min(ans, temp);
        if (i == 0) break;
    }
    cout << ans << "\n";
    return 0;
}