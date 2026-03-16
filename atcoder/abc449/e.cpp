#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(m + 1);
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i + 1] = x;
        cnt[x]++;
    }

    int minc = n, maxc = 0;
    for (int v = 1; v <= m; v++) {
        minc = min(minc, cnt[v]);
        maxc = max(maxc, cnt[v]);
    }

    vector<int> freq(maxc + 1);
    vector<vector<int>> by_cnt(maxc + 1);
    for (int v = 1; v <= m; v++) {
        freq[cnt[v]]++;
        by_cnt[cnt[v]].push_back(v);
    }

    vector<int> level;
    vector<long long> pref;
    long long cur = 0, tot = 0;
    for (int c = 0; c < maxc; c++) {
        cur += freq[c];
        if (c < minc || cur == 0) {
            continue;
        }
        tot += cur;
        level.push_back(c);
        pref.push_back(tot);
    }

    int q;
    cin >> q;
    vector<long long> ans(q);
    vector<vector<pair<int, long long>>> ask(maxc);

    struct Fenwick {
        int n;
        vector<int> bit;
        Fenwick() {}
        explicit Fenwick(int n) : n(n), bit(n + 1, 0) {}
        void add(int idx, int val) {
            for (; idx <= n; idx += idx & -idx) {
                bit[idx] += val;
            }
        }
        int kth(long long k) const {
            int idx = 0;
            int step = 1;
            while ((step << 1) <= n) {
                step <<= 1;
            }
            for (int d = step; d; d >>= 1) {
                int nxt = idx + d;
                if (nxt <= n && bit[nxt] < k) {
                    idx = nxt;
                    k -= bit[nxt];
                }
            }
            return idx + 1;
        }
    } fw(m);

    while (q--) {
        long long x;
        cin >> x;
        int id = (int)ans.size() - q - 1;
        if (x <= n) {
            ans[id] = a[x];
            continue;
        }
        x -= n;
        if (x > tot) {
            ans[id] = (x - tot - 1) % m + 1;
            continue;
        }

        int p = (int)(lower_bound(pref.begin(), pref.end(), x) - pref.begin());
        long long prv = (p ? pref[p - 1] : 0LL);
        int c = level[p];
        long long k = x - prv;
        ask[c].push_back({id, k});
    }

    for (int c = 0; c < maxc; c++) {
        for (int v : by_cnt[c]) {
            fw.add(v, 1);
        }
        for (auto [id, k] : ask[c]) {
            ans[id] = fw.kth(k);
        }
    }

    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}