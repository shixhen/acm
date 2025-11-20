#include <bits/stdc++.h>

using namespace std;

constexpr int N = (1 << 20) + 5;

long long a[25];                    // 第i头奶牛产生的牛奶量
map<long long, vector<int>> mp;     // 记录牛奶量是否存在
bool vis[N];                        //去重
int n;

void dfs(int d, long long sum, int cur) {
    if (d == n) {
        if (mp.count(sum)) {
            for (auto &x : mp[sum]) {
                vis[x | cur] = true;
            }
        }
        cur |= (1 << (d - 1));
        if (mp.count(sum + a[d])) {
            for (auto &x : mp[sum + a[d]]) {
                vis[x | cur] = true;
            }
        }
        if (mp.count(sum - a[d])) {
            for (auto &x : mp[sum - a[d]]) {
                vis[x | cur] = true;
            }
        }
        return;
    }
    if (d == (n >> 1)) {
        mp[sum].push_back(cur);
        cur |= (1 << (d - 1));
        mp[sum + a[d]].push_back(cur);
        mp[sum - a[d]].push_back(cur);
        return;
    }
    dfs(d + 1, sum - a[d], cur | (1 << (d - 1)));
    dfs(d + 1, sum, cur);
    dfs(d + 1, sum + a[d], cur | (1 << (d - 1)));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, 0, 0);
    dfs((n >> 1) + 1, 0, 0);
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (vis[i]) {
            ans++;
        }
    }
    cout << ans - 1 << "\n";
    return 0;
}