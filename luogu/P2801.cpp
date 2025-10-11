#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int block = sqrt(n);
    int t = (n + block - 1) / block;
    vector<vector<int>> b(t, vector<int>(block));
    vector<int> st(t);
    vector<int> ed(t);
    vector<int> add(t);
    for (int i = 0; i < n; i++) {
        b[i / block][i % block] = a[i];
    }
    for (int i = 0; i < t; i++) {
        st[i] = i * block;
        ed[i] = min(n - 1, (i + 1) * block - 1);
        add[i] = 0;
    }
    b[t - 1].resize(n % block);
    for (int i = 0; i < t; i++) {
        sort(b[i].begin(), b[i].end());
    }
    char c;
    int l, r, w, stb, edb;
    while (q--) {
        cin >> c >> l >> r >> w;
        l--, r--;
        if (c == 'M') {
            stb = l / block;
            edb = r / block;
            if (stb == edb) {
                for (int i = l; i <= r; i++) {
                    a[i] += w;
                }
                for (int i = st[stb]; i <= ed[stb]; i++) {
                    b[stb][i % block] = a[i];
                }
                sort(b[stb].begin(), b[stb].end());
            } else {
                for (int i = l; i < (stb + 1) * block; i++) {
                    a[i] += w;
                }
                for (int i = st[stb]; i <= ed[stb]; i++) {
                    b[stb][i % block] = a[i];
                }
                for (int i = stb + 1; i < edb; i++) {
                    add[i] += w;
                }
                for (int i = edb * block; i <= r; i++) {
                    a[i] += w;
                }
                for (int i = st[edb]; i <= ed[edb]; i++) {
                    b[edb][i % block] = a[i];
                }
                sort(b[stb].begin(), b[stb].end());
                sort(b[edb].begin(), b[edb].end());
            }
        } else {
            stb = l / block;
            edb = r / block;
            int ans = 0;
            if (stb == edb) {
                for (int i = l; i <= r; i++) {
                    if (a[i] + add[stb] >= w) ans++;
                }
                cout << ans << "\n";
            } else {
                for (int i = l; i < (stb + 1) * block; i++) {
                    if (a[i] + add[stb] >= w) ans++;
                }
                for (int i = stb + 1; i < edb; i++) {
                    auto it = lower_bound(b[i].begin(), b[i].end(), w - add[i]);
                    ans += b[i].end() - it;
                }
                for (int i = edb * block; i <= r; i++) {
                    if (a[i] + add[edb] >= w) ans++;
                }
                cout << ans << "\n";
            }
        }
    }
    return 0;
}