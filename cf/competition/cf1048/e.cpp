#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> edge(n + 1);
    for (int i = 2, u; i <= n; i++) {
        cin >> u;
        edge[u].push_back(i);
    }

    int minh = 0x3f3f3f3f;  // 最浅叶子的深度
    vector<int> height(n + 1);
    height[1] = 1;
    function<void(int)> dfs = [&](int u) {
        for (auto &v : edge[u]) {
            height[v] = height[u] + 1;
            dfs(v);
        }
        if (edge[u].empty()) {
            minh = min(minh, height[u]);
        }
    };
    dfs(1);

    // cnt[d] = 深度为 d 的节点数
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cnt[height[i]]++;
    }

    // 背包 dp：dp[x] = 是否能凑出 x 个节点
    bitset<1005> dp;
    dp.reset();
    dp[0] = 1;  // 初始：什么都不选可以得到 0

    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) continue;
        for (int j = n; j >= cnt[i]; j--) {
            if (dp[j - cnt[i]]) dp[j] = 1;
        }
    }

    // 检查能否形成从 min(k, n-k) 到 max(k, n-k) 的某个和
    int ans = minh - 1;  // 默认至少能有深度-1（因为可能差一点）
    if (dp[k] || dp[n - k]) ans = minh;  // 如果能刚好分配，答案就是最浅叶深度


    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _; cin >> _;
    while (_--) solve();
    return 0;
}
