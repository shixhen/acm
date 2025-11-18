#include <bits/stdc++.h>

using namespace std;

void solve() {
    int k;
    cin >> k;
    vector<pair<int, int>> ans;
    int num = 1;
    ans.push_back({1, 1});
    int sum = 0;
    int add = 1;
    while (sum + add <= k) {
        sum += add;
        add++;
        ans.push_back({1, add});
    }
    add = 1;
    while (sum + add <= k) {
        sum += add;
        add++;
        ans.push_back({add, 1});
    }
    add = 1;
    while (sum + add <= k) {
        sum += add;
        add++;
        ans.push_back({-add, 2});
    }
    int more = k - sum;
    for (int i = 1; i <= more; i++) {
        ans.push_back({5000 + i * 2, 5000 + i * 2});
        ans.push_back({5000 + i * 2, 5001 + i * 2});
    }
    cout << ans.size() << '\n';
    for (auto &i: ans) {
        cout << i.first << " " << i.second << '\n';
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}