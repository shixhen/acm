#include <bits/stdc++.h>

using namespace std;

struct p {
    long long w;
    long long r;

    bool operator<(const p &b) const {
        return r > b.r;
    }
};

bool cmp(const p &a, const p &b) {
    return a.w < b.w;
}

void solve() {
    int n;
    cin >> n;
    vector<p> a(n);
    for (auto &x : a) {
        cin >> x.w;
    }
    for (auto &x : a) {
        cin >> x.r;
    }
    sort(a.begin(), a.end(), cmp);
    priority_queue<p> q;
    int ans = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        q.push(a[i]);
        sum += a[i].w;
        while (!q.empty() && sum > q.top().r * q.size()) {
            sum -= q.top().w;
            q.pop();
        }
        ans = max(ans, (int)q.size());
    }
    cout << ans << "\n";
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