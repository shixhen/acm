#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, s, x;
    cin >> n >> m;
    vector<int> cnt(m + 1, 0);
    vector<vector<int>> ss(n + 1, vector<int>());
    int t;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        while (s--) {
            cin >> x;
            ss[i].push_back(x);
            cnt[x]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        if (cnt[i] == 0) {
            cout << "NO\n";
            return;
        }
    }
    int total = 0;
    for (int i = 1; i <= n; i++) {
        bool f = true;
        for (auto x : ss[i]) {
            if (cnt[x] <= 1) {
                f = false;
                break;
            }
        }
        if (f) {
            total++;
        }
    }
    if (total <= 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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