#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<int> vis(k + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q1;
    priority_queue<pair<int, int>> q2;
    for (int i = n; i >= 1; i--) {
        if (!a[i] || vis[a[i]]) continue;
        q1.push({i, a[i]});
        vis[a[i]] = 1;
    }
    for (int i = 1; i <= k; i++) {
        if (!vis[i]) {
            q1.push({-1, i});
        }
    }
    vector<int> vis2(k + 1);
    for (int i = 1; i <= n; i++) {
        if (!a[i]) {
            while (!q1.empty() && q1.top().first < i && q1.top().first != -1) {
                q1.pop();
            }
            if (i == 1) {
                a[i] = q1.top().second;
                if (q1.top().first == -1) {
                    q1.pop();
                }
            } else if (!q1.empty() && q1.top().first == -1) {
                a[i] = q1.top().second;
                q1.pop();
            } else if (q1.empty()) {
                a[i] = q2.top().second;
            } else {
                int dis1 = q1.top().first - i;
                int dis2 = i - q2.top().first;
                if (dis1 <= dis2) {
                    a[i] = q1.top().second;
                } else {
                    a[i] = q2.top().second;
                }
            }
            
        }
        if (!vis2[a[i]]) {
            q2.push({i, a[i]});
            vis2[a[i]] = 1;
        }
        
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}