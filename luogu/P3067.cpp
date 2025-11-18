#include <bits/stdc++.h>

using namespace std;

constexpr int N = (1 << 20) + 5;

long long a[25];             // 第i头奶牛产生的牛奶量
map<long long, bool> mp;    // 记录牛奶量是否存在

int n;
int ans;

void dfs(int d, long long sum) {
    if (d == n) {
        if (mp.count(sum)) {
            cout << "sum " << sum << '\n';
            ans++;
        }
        if (mp.count(sum + a[d])) {
            cout << "sum " << sum + a[d] << '\n';
            ans++;
        }
        if (mp.count(sum - a[d])) {
            cout << "sum " << sum - a[d] << '\n';
            ans++;
        }
        return;
    }
    if (d == (n >> 1)) {
        mp[sum] = true;
        mp[sum + a[d]] = true;
        return;
    }
    dfs(d + 1, sum - a[d]);
    dfs(d + 1, sum);
    dfs(d + 1, sum + a[d]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, 0);
    dfs((n >> 1) + 1, 0);
    cout << ans - 1 << '\n';

    return 0;
}