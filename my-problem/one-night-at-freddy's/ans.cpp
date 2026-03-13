#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> v(m + 1);
    reverse(a.begin(), a.end());
    for (int i = 1; i <= l; i++) {
        int idx;
        cin >> idx;
        v[idx]++;
        if (!a.empty() && a.back() == i) {
            int max_idx = 1;
            for (int i = 2; i <= m; i++) {
                if (v[i] > v[max_idx]) {
                    max_idx = i;
                }
            }
            v[max_idx] = 0;   
            cout << max_idx << endl;
            cout.flush();
            a.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}