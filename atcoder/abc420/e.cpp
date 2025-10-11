#include <bits/stdc++.h>

using namespace std;

vector<int> f;

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    f.resize(n + 5);
    vector<int> cnt(n + 10);
    vector<int> st(n + 10);
    iota(f.begin(), f.end(), 0);
    int u, v, op;
    //cout << cnt[find(2)] << endl;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> u >> v;
            u = find(u);
            v = find(v);
            if (f[u] != v) {
                cnt[v] += cnt[u];
                cnt[u] = 0;
                f[u] = v;
            }
        } else if (op == 2) {
            cin >> v;
            if (st[v] == 0) {
                st[v] = 1;
                cnt[find(v)]++;
            } else {
                st[v] = 0;
                cnt[find(v)]--;
            }
        } else {
            cin >> v;
            if (cnt[find(v)]) {
                //cout << find(v) << "  " << cnt[find(v)] << endl;
                cout << "Yes" << "\n";
            } else {
                cout << "No" << "\n";
            }
        }
    }
    return 0;
}