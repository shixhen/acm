#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> vis(n + 1);
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] != -1 && vis[b[i]]) {
            flag = true;
        }
        if (b[i] != -1) {
            vis[b[i]] = 1;
        }
    }
    if (flag) {
        cout << "No\n";
        return;
    }
    vector<int> r(n + 1);
    vector<int> l(n + 1);
    r[1] = k;
    for (int i = 2; i <= n; i++) {
        r[i] = max(1, r[i - 1] - 1);
    }
    l[n] = k;
    for (int i = n - 1; i >= 1; i--) {
        l[i] = max(1, l[i + 1] - 1);
    }
    set<int> s;
    int ll = 1, rr = 1;
    s.insert(a[1]);
    for (int i = 1; i <= n; i++) {
        while (rr < i + r[i] - 1) {
            rr++;
            s.insert(a[rr]);
        }
        while (ll < i - l[i] + 1) {
            s.erase(a[ll]);
            ll++;
        }
        if (b[i] == -1) {
            continue;
        }
        if (vis[b[i]] && !s.count(b[i])) {
            cout << "No\n";
            return;
        }
    }
    ll = 1, rr = 1;
    while (s.size()) {
        s.erase(s.begin());
    }
    s.insert(b[1]);
    for (int i = 1; i <= n; i++) {
        while (rr < i + r[i] - 1) {
            rr++;
            s.insert(b[rr]);
        }
        while (ll < i - l[i] + 1) {
            s.erase(b[ll]);
            ll++;
        }
        if (vis[a[i]] && !s.count(a[i])) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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