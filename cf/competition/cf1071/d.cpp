#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> vis(1 << n);
    vector<int> ans;
    ans.push_back((1 << n) - 1);
    vis.back() = 1;
    for (int i = n - 1; i >= 0; i--) {
        int num = 1 << (n - i - 1);
        for (int j = 0; j < num; j++) {
            int t = ((1 << i) - 1) | (j << (i + 1));
            ans.push_back(t);
            vis[t] = 1;
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        if (!vis[i]) {
            ans.push_back(i);
        }
    }
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}