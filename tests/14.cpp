#include <bits/stdc++.h>

using namespace std;

struct Fenwick {
    int n;
    vector<int> tree;

    Fenwick() : n(0) {}

    explicit Fenwick(int n_) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        tree.assign(n + 1, 0);
    }

    void add(int x, int v) {
        for (int i = x; i <= n; i += i & -i) tree[i] += v;
    }

    int query(int x) const {
        int res = 0;
        for (int i = x; i > 0; i -= i & -i) res += tree[i];
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long k;
    cin >> n >> k;
    vector<pair<long long, long long>> p(n);
    for (auto &[x, y] : p) cin >> x >> y;

    // For equal x, sort y in descending order to avoid counting vertical pairs.
    sort(p.begin(), p.end(), [](const pair<long long, long long> &a,
                                const pair<long long, long long> &b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });

    auto count_ge = [&](long long mid) -> long long {
        vector<long long> t(n);
        for (int i = 0; i < n; i++) {
            t[i] = p[i].second - mid * p[i].first;
        }

        vector<long long> vals = t;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        Fenwick bit((int)vals.size());
        long long cnt = 0;

        for (int i = 0; i < n; i++) {
            int pos = (int)(lower_bound(vals.begin(), vals.end(), t[i]) - vals.begin()) + 1;
            cnt += bit.query(pos);
            bit.add(pos, 1);
        }
        return cnt;
    };

    const long long LIM = 4000000000LL;
    long long l = -LIM, r = LIM;
    while (l < r) {
        long long mid = l + (r - l + 1) / 2;
        if (count_ge(mid) >= k) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << '\n';
    return 0;
}