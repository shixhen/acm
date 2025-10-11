#include <bits/stdc++.h>

using namespace std;

int ask(int s, vector<int>& v) {
    cout << "? ";
    cout << s;
    cout << " " << v.size();
    for (auto &i : v) {
        cout << " " << i;
    }
    cout << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> cnt(n + 1, vector<int>());
    int maxn = 0;
    int maxv;
    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }
    for (int i = 1; i <= n; i++) {
        int res = ask(i, v);
        cnt[res].push_back(i);
        if (res > maxn) {
            maxn = res;
            maxv = i;
        }
    }
    vector<int> ans;
    ans.push_back(maxv);
    for (int i = maxn - 1; i >= 1; i--) {
        vector<int> q;
        for (auto &k : ans) {
            q.push_back(k);
        }
        for (int j = 1; j < i; j++) {
            for (auto &k : cnt[j]) {
                q.push_back(k);
            }
        }
        for (auto &k : cnt[i]) {
            q.push_back(k);
            if (ask(maxv, q) == maxn) {
                ans.push_back(k);
                break;
            }
            q.pop_back();
        }
    }
    cout << "! ";
    cout << ans.size();
    for (auto &i: ans) {
        cout << " " << i;
    }
    cout << endl;
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