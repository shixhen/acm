#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 5;
constexpr long long mod = 998244353;

int f[N];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        f[i] = i;
    }
    vector<int> a(n);
    vector<int> d(n);
    for (auto &x : a) cin >> x;
    if (a[0] != 0) {
        cout << "0\n";
        return;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1] + 1) {
            cout << "0\n";
            return;
        }
        int j = a[i - 1];
        set<int> s;
        while (j && j >= a[i]) {
            s.insert(find(j));
            j = a[j - 1];
        }
        if (a[i]) j++;
        if (a[i] != j) {
            cout << "0\n";
            return;
        }
        if (j) {
            if (s.count(find(j - 1))) {
                cout << "0\n";
                return;
            }
            f[i] = find(j - 1);
        } else {
            s.insert(0);
            d[i] = s.size();
        }
    }
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        if (find(i) != i) continue;
        if (d[i] >= m) {
            cout << "0\n";
            return;
        }
        ans = ans * (m - d[i]) % mod;
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }

    return 0;
}