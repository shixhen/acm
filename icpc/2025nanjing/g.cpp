#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    vector<long long> b(n + 1);
    long long suma = 0, sumb = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        suma += a[i];
    } 
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        sumb += b[i];
    }
    sort(a.begin() + 1, a.end(), greater<long long>());
    sort(b.begin() + 1, b.end());
    int q;
    cin >> q;
    map<long long, vector<int>> mp;
    vector<long long> ans(q + 1);
    for (int i = 1; i <= q; i++) {
        cin >> ans[i];
        mp[ans[i]].push_back(i); 
    }
    int p = n;
    for (auto &[k, v] : mp) {
        long long t1 = suma - k * sumb;
        long long t2 = (suma - a[p]) - k * (sumb - b[p]);
        while (p > 0 && t2 >= t1) {
            suma -= a[p];
            sumb -= b[p];
            p--;
            t1 = suma - k * sumb;
            t2 = (suma - a[p]) - k * (sumb - b[p]);
        }
        for (auto &idx : v) {
            ans[idx] = t1;
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}