#include <bits/stdc++.h>

using namespace std;

struct node {
    long long x;
    long long y;
    long long z;
};

bool cmp1(const node &a, const node &b) {
    return a.x < b.x;
}

struct Cmp {
    bool operator()(const node &a, const node &b) {
        return a.z - a.y < b.z - b.y;
    }
};

void solve() {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(m);
    for (auto &x : a) cin >> x;
    vector<node> p(n);
    for (auto &it : p) {
        cin >> it.x >> it.y >> it.z;
        k -= it.y;
    }
    sort(p.begin(), p.end(), cmp1);
    sort(a.begin(), a.end());
    priority_queue<node, vector<node>, Cmp> pq;
    int j = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        while (j < n && p[j].x <= a[i]) {
            pq.push(p[j]);
            j++;
        }

        if (!pq.empty()) {
            pq.pop();
            ans++;
        }
    }
    while (j < n) {
        pq.push(p[j]);
        j++;
    }
    vector<node> rest;
    while (!pq.empty()) {
        rest.push_back(pq.top());
        pq.pop();
    }
    sort(rest.begin(), rest.end(), Cmp());
    for (auto &it : rest) {
        if (k >= it.z - it.y) {
            k -= it.z - it.y;
            ans++;
        } else {
            break;
        }
    }

    cout << ans << "\n";

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