#include <bits/stdc++.h>

using namespace std;

vector<int> tot;    
vector<int> cnt1;
vector<int> cnt0;
vector<int> st;
long long ans = 0;
int n, m;

bool check(int x) {
    return cnt0[x] == tot[x] - 1 && cnt1[x] == 1;
}
struct segTree {

    vector<int> sum;
    vector<vector<long long>> seg; 
    void init(int n) {
        n += 10;
        sum.resize(n << 2);
        seg.resize(n << 2);
    }

    void pushup(int p) {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
    }
    
    void build(int p, int l, int r) {
        if (l == r) {
            sum[p] = 1;
            for (auto &x : seg[p]) {
                cnt1[x]++;
                if (check(x) && !st[x]) {
                    ans += x * x;
                    st[x] = 1;
                }
            }
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
    }

    void insert(int p, int l, int r, int ql, int qr, int idx) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            seg[p].push_back(idx);
            tot[idx]++;
            return;
        }
        int mid = (l + r) >> 1;
        insert(p << 1, l, mid, ql, qr, idx);
        insert(p << 1 | 1, mid + 1, r, ql, qr, idx);
    }

    void update(int p, int l, int r, int pos) {
        if (l == r) {
            sum[p]--;
            if (sum[p] == 1) {
                for (auto &x : seg[p]) {
                    cnt1[x]++;
                    if (check(x) && !st[x]) {
                        ans += x * x;
                        st[x] = 1;
                    }
                }
            } else if (sum[p] == 0) {
                for (auto &x : seg[p]) {
                    cnt0[x]++;
                    cnt1[x]--;
                    if (check(x) && !st[x]) {
                        ans += x * x;
                        st[x] = 1;
                    } else if (!check(x) && st[x]) {
                        ans -= x * x;
                        st[x] = 0;
                    }
                }
            }
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            update(p << 1, l, mid, pos);
        } else {
            update(p << 1 | 1, mid + 1, r, pos);
        }
        pushup(p);
        if (sum[p] == 1) {
            for (auto &x : seg[p]) {
                cnt1[x]++;
                if (check(x) && !st[x]) {
                    ans += x * x;
                    st[x] = 1;
                }
            }
        } else if (sum[p] == 0) {
            for (auto &x : seg[p]) {
                cnt0[x]++;
                cnt1[x]--;
                if (check(x) && !st[x]) {
                    ans += x * x;
                    st[x] = 1;
                } else if (!check(x) && st[x]) {
                    ans -= x * x;
                    st[x] = 0;
                }
            }
        }
    }

    int query(int p, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return sum[p];
        int mid = (l + r) >> 1;
        return query(p << 1, l, mid, ql, qr) + query(p << 1 | 1, mid + 1, r, ql, qr);
    }
};

void solve() {
    cin >> n >> m;
    cnt0.assign(m + 1, 0);
    cnt1.assign(m + 1, 0);
    tot.assign(m + 1, 0);
    st.assign(m + 1, 0);
    ans = 0;
    vector<int> a(n + 1);
    int l, r;
    segTree t;
    t.init(n);
    for (int i = 1; i <= m; i++) {
        cin >> l >> r;
        l++;
        r++;
        t.insert(1, 1, n, l, r, i);
    }
    t.build(1, 1, n);
    cout << ans << " ";
    //cout << cnt0[1] << "------\n";
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = (a[i] + ans) % n;
        t.update(1, 1, n, a[i] + 1);
        cout << ans << " ";
    }
    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        solve();
    }



    return 0;
}