#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    reverse(a.begin(), a.end());
    priority_queue<int, vector<int>, greater<int>> q;
    priority_queue<int, vector<int>, greater<int>> q2;
    int t = min(m, n + 1);
    while (t--) {
        q.push(0);
    }
    for (int i = 1; i <= l; i++) {
        int x = q.top();
        q.pop();
        q.push(x + 1);
        if (!a.empty() && a.back() == i) {
            while (q.size() > 1) {
                q2.push(q.top());
                q.pop();
            }
            while (!q.empty()) {
                q.pop();
            }
            swap(q, q2);
            a.pop_back();
            while (q.size() < a.size() + 1 && q.size() < m) {
                q.push(0);
            }
        }
    }
    while (q.size() > 1) {
        q.pop();
    }
    cout << q.top() << "\n";
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