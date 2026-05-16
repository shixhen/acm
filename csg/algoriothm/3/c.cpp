#include <bits/stdc++.h>

using namespace std;


vector<pair<pair<int, int>, int>> p;  // {{x, y}, original_index}
long long dis = 0x3f3f3f3f3f3f;
int ansa = -1, ansb = -1;

long long calc(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    long long dx = a.first.first - b.first.first;
    long long dy = a.first.second - b.first.second;
    return dx * dx + dy * dy;
}

void dfs(int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    dfs(l, mid);
    dfs(mid + 1, r);

    vector<pair<pair<int, int>, int>> tmpl, tmpr;
    long long midx = p[mid].first.first;

    for (int i = l; i <= mid; i++) {
        long long dx = 1LL * p[i].first.first - midx;
        if (dx * dx <= dis) tmpl.push_back(p[i]);
    }
    for (int i = mid + 1; i <= r; i++) {
        long long dx = 1LL * p[i].first.first - midx;
        if (dx * dx <= dis) tmpr.push_back(p[i]);
    }

    sort(tmpl.begin(), tmpl.end(), [](const auto &a, const auto &b) {
        return a.first.second < b.first.second;
    });
    sort(tmpr.begin(), tmpr.end(), [](const auto &a, const auto &b) {
        return a.first.second < b.first.second;
    });

    for (int i = 0; i < (int)tmpl.size(); i++) {
        for (int k = 0; k < (int)tmpr.size(); k++) {
            long long dy = 1LL * tmpr[k].first.second - tmpl[i].first.second;
            if (dy * dy > dis) continue;

            long long d = calc(tmpl[i], tmpr[k]);
            int idxa = min(tmpl[i].second, tmpr[k].second);
            int idxb = max(tmpl[i].second, tmpr[k].second);

            if (d < dis) {
                dis = d;
                ansa = idxa;
                ansb = idxb;
            } else if (d == dis) {
                if (idxa < ansa || (idxa == ansa && idxb < ansb)) {
                    ansa = idxa;
                    ansb = idxb;
                }
            }
        }
    }
}

void solve(int n) {
    p.assign(n, {{0, 0}, 0});
    for (int i = 0; i < n; i++) {
        cin >> p[i].first.first >> p[i].first.second;
        p[i].second = i;  // 保存原始编号
    }
    sort(p.begin(), p.end());  // 按 x 坐标排序
    dis = 0x3f3f3f3f3f3f;
    ansa = -1;
    ansb = -1;
    dfs(0, n - 1);
    cout << ansa << " " << ansb << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        solve(n);
    }

    return 0;
}