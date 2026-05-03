#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int64> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int64 L = 2LL * n - 1;

    // c1[t]: i<n 的 type1 数量（来=>来=>来...）
    // c2[t]: i<n 的 type2 数量（来=>回=>来=>回...）
    // c3[t]: i<n 的 type3 数量（来=>回=>回=>回...）
    // cn[t]: i=n 的数量（只有来，等价于 type1）
    vector<int64> c1(m + 1, 0), c2(m + 1, 0), c3(m + 1, 0), cn(m + 1, 0);

    // t > m 的格子，在前 m 轮里都只会贡献第 1 轮一次
    int64 firstOnly = 0;

    // 处理 i < n（每轮两次检查）
    for (int i = 1; i <= n - 1; i++) {
        int64 ai = a[i];
        int64 t = ai / L;
        int64 r = ai % L;

        if (t > m) {
            firstOnly++;
            continue;
        }

        int64 x = 2LL * (n - i); // 来->回 的同轮时间差
        int64 y = 2LL * i - 1;   // 回->下轮来 的时间差

        // 分型（由 r 与 x,y 的关系决定）
        if (r >= x) {
            // type1: 来=>来=>来...
            c1[(int)t]++;
        } else if (r < y) {
            // type2: 来=>回=>来=>回...
            c2[(int)t]++;
        } else {
            // type3: 来=>回=>回=>回...
            c3[(int)t]++;
        }
    }

    // 处理 i = n（每轮一次检查）
    {
        int64 ai = a[n];
        int64 t = ai / L;
        if (t > m) {
            firstOnly++;
        } else {
            cn[(int)t]++;
        }
    }

    vector<int64> ans(m + 1, 0);
    ans[1] += firstOnly;

    // 把一个等差序列 (start, step) 的贡献加到 ans
    auto add_ap = [&](int start, int step, int64 val) {
        if (val == 0 || start > m) return;
        for (int k = start; k <= m; k += step) ans[k] += val;
    };

    for (int t = 0; t <= m; t++) {
        int64 A = c1[t] + c3[t] + cn[t];

        // type1 + type3(回链) + i=n:
        // 轮次 1, 1+(t+1), 1+2(t+1), ...
        if (A > 0) {
            int d = t + 1;
            add_ap(1, d, A);
        }

        // type3 额外的首轮“来”一次
        if (c3[t] > 0) {
            ans[1] += c3[t];
        }

        // type2
        if (c2[t] > 0) {
            if (t == 0) {
                // t=0 时：每轮来和回都能清，共 2 次
                for (int k = 1; k <= m; k++) ans[k] += 2LL * c2[t];
            } else {
                int d = 2 * t + 1;
                // 来链：1, 1+d, 1+2d, ...
                add_ap(1, d, c2[t]);
                // 回链：1+t, 1+t+d, ...
                add_ap(1 + t, d, c2[t]);
            }
        }
    }

    for (int k = 1; k <= m; k++) {
        if (k > 1) cout << ' ';
        cout << ans[k];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}