#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> p(n + 1);
    priority_queue<int, vector<int>, greater<int>> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i % 2) q2.push(a[i]);
        else q1.push(a[i]);
        p[a[i]] = i;
    }
    for (int i = 0; i <= n - 4; i++) {
        if (i % 2) {
            int idx = p[q2.top()];
            q2.pop();
            if (idx == i) continue;
            int idx2 = idx - 1;
            if (idx2 == i + 1) idx2 = idx + 1;
            swap(a[idx], a[i]);
            p[a[i]] = i;
            p[a[idx]] = idx;
            swap(a[i + 1], a[idx2]);
            p[a[i + 1]] = i + 1;
            p[a[idx2]] = idx2;
        } else {
            int idx = p[q1.top()];
            q1.pop();
            if (idx == i) continue;
            int idx2 = idx - 1;
            if (idx2 == i + 1) idx2 = idx + 1;
            swap(a[idx], a[i]);
            p[a[i]] = i;
            p[a[idx]] = idx;
            swap(a[i + 1], a[idx2]);
            p[a[i + 1]] = i + 1;
            p[a[idx2]] = idx2;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}