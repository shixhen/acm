#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, k, x, y, d;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n + 1, vector<pair<int, int>>());
    while (m--) {
        cin >> x >> y >> d;
        g[x].emplace_back(y, d);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({n, n});
    vector<int> ans;
    while (q.size()) {
        auto [dis, cur] = q.top();
        q.pop();
        if (cur == 1) {
            ans.push_back(dis - 1);
            if (ans.size() == k) {
                break;
            }
            continue;
        }
        for (auto [v, d] : g[cur]) {
            q.push({dis - cur + v + d, v});
        }
    }
    for (auto x : ans) {
        cout << x << '\n';
    }
    k -= ans.size();
    while (k--) {
        cout << -1 << '\n';
    }
    return 0;
}   