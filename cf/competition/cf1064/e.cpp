#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + n + 1, greater<int>());
    int c;
    while (q--) {
        cin >> c;
        vector<int> b;
        for (int i = 29; i >= 0; i--) {
            if (c & (1 << i)) {
                b.push_back(1 << i);
            }
        }
        priority_queue<int> q;
        for (int i = 1; i <= min((int) b.size(), n); i++) {
            q.push(a[i]);
        }
        for (auto &x : b) {
            int cur = q.top();
            q.pop();
            c -= min(cur, x);
            q.push(max(0, cur - x));
        }
        cout << c << "\n";
    }
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