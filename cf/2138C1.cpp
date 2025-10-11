#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> edge(n + 1, vector<int>());
    for (int i = 2, x; i <= n; i++) {
        cin >> x;
        edge[x].push_back(i);
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
    vector<int> cnt(n + 2);
    for (int i = 1; i <= n; i++) {
        cnt[height[i]]++;
    }
    vector<int> dp(n + 1);
    dp[0] = 1;
    int sum = 0;
    for (int i = 1; i <= minh; i++) {
        sum += cnt[i];
        for (int j = n; j >= cnt[i]; j--) {
            dp[j] |= dp[j - cnt[i]];
        }
    }
    //cout << sum - k << "\n";
    if (sum <= k || sum <= n - k || dp[k] || dp[n - k]) { 
        cout << minh << "\n";
        return;
    }
    for (int i = sum - k; i <= n - k; i++) {
        //cout << i << endl;
        if (dp[i]) {
            cout << minh << "\n";
            return;
        }
        
    }
    for (int i = k - n + sum; i <= k; i++) {
        if (dp[i]) {
            cout << minh << "\n";
            return;
        }
    }
    
    cout << minh - 1 << "\n";
    
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