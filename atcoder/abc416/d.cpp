#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    long long m;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<long long> a(n);
        vector<long long> b(n);
        for (auto &i: a)
            cin >> i;
        for (auto &i: b)
            cin >> i;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<long long>());
        long long ans = 0;
        int p = 0;
        for (int i = 0; i < n; i++) {
            ans += a[i] + b[i];
            while (p < n and a[p] + b[i] < m) {
                p++;
            }
            if (p < n and a[p] + b[i] >= m) {
                p++;
                ans -= m;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}