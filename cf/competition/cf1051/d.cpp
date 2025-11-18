#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll mod = 1e9 + 7;

int lowbit(int x) {
    return x & (-x);
}

struct Tvec {
    vector<ll> tree;
    int n;
    Tvec() {};
    Tvec(int _n) : n(_n) {
        tree.resize(n + 1);
    }

    void set(int _n) {
        n = _n;
        tree.resize(n + 1);
    }

    void update(int x, ll v) {
        while (x <= n && x) {
            tree[x] = (tree[x] + v) % mod;
            x += lowbit(x);
        }

    }

    ll query(int x) {
        ll res = 0;
        while (x) {
            res = (res + tree[x]) % mod;
            x -= lowbit(x);
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll temp;
    vector<Tvec> maxn(n + 1, Tvec(n + 1));
    vector<Tvec> mp(n + 1, Tvec(n + 1));
    for (int i = 1; i <= n; i++) {
        // a[i] >= maxn
        for (int j = 0; j <= n; j++) {
            temp = mp[j].query(a[i] + 1);
            maxn[a[i]].update(j + 1, temp);
            mp[j].update(a[i] + 1, temp);
        }
        // mp <= a[i] < maxn
        for (int j = a[i] + 1; j <= n; j++) {
            temp = maxn[j].query(a[i] + 1);
            maxn[j].update(a[i] + 1, temp);
            mp[a[i]].update(j + 1, temp);
        }
        maxn[a[i]].update(1, 1);
        mp[0].update(a[i] + 1, 1);
    }
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = (ans + maxn[i].query(n + 1)) % mod;
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) { solve(); }
    return 0;
}