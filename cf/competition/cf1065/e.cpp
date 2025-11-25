#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> vis(n + 1);
    vector<int> a;
    for (int i = 3; i <= n; i++) {
        if (vis[i]) continue;
        if (i * 4 > n) continue;
        a.push_back(i * 2);
        a.push_back(i);
        vis[i] = 1;
        vis[i * 2] = 1;
        int t = i * i - i;
        for (int j = i * 3; j <= n; j += t) {
            a.push_back(j);
            vis[j] = 1;
        }
    }
    vector<int> ans;
    int j = 1;
    int f = true;
    for (auto &x : a) {
        ans.push_back(x);
        //cout << x << " ----";
        if (!f) {
            f = true;
            continue;
        }
        if (f) {
            if (j <= n) {
            //cout << j << " ----";
            ans.push_back(j++);
            }
            while (j <= n && vis[j]) j++;
            f = false;
        }
    }
    for (; j <= n; j++) {
        if (vis[j]) continue;
        ans.push_back(j);
    }
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}