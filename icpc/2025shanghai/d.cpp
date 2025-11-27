#include <bits/stdc++.h>

using namespace std;

int a[1 << 17];

vector<int> dfs(int l, int d) {
    if (d == 0) {
        return {a[l]};
    }
    vector<int> res;
    vector<int> va = dfs(l, d - 1);
    vector<int> vb = dfs(l + (1 << (d - 1)), d - 1);
    for (int i = 0; i < va.size(); i++) {
        res.push_back(va[i] + vb[i]);
    }
    for (auto &x : va) {
        res.push_back(x);
    }
    for (auto &x : vb) {
        res.push_back(x);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int res = 1;
    int n;
    cin >> n;
    for (int i = 1; i <= (1 << n); i++) {
        cin >> a[i];
    }
    int ans = 0;
    vector<int> v = dfs(1, n);
    for (auto &x : v) {
        ans ^= x;
    }
    cout << ans << "\n";
    return 0;
}