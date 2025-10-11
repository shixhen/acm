#include <bits/stdc++.h>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b, int p) {
    if (a.size() <= p) {
        return false;
    }
    if (b.size() <= p) {
        return true;
    }
    for (int i = p; ; i++) {
        if (i >= a.size()) return true;
        if (i >= b.size()) return false;
        if (a[i] > b[i]) return false;
        if (a[i] < b[i]) return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    int max_len = 0;
    vector<vector<int>> a(n + 1, vector<int>());
    for (int i = 1, k; i <= n; i++) {
        cin >> k;
        max_len = max(max_len, k);
        a[i].resize(k + 1);
        for (int j = 1; j <= k; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> ans(max_len + 1);
    int p = 1;
    while (p <= max_len) {
        for (int i = 2; i <= n; i++) {
            if (cmp(a[i], a[1], p)) {
                swap(a[i], a[1]);
            }
        }
        while (p < a[1].size()) {
            ans[p] = a[1][p];
            p++;
        }
    }
    for (int i = 1; i <= max_len; i++) {
        cout << ans[i] << " \n"[i == max_len];
    }
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