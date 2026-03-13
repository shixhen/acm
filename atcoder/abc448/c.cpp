#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vector<int> d = a;
    sort(a.begin(), a.end());
    while (q--) {
        int k;
        cin >> k;
        vector<int> b(k);
        for (auto &x : b) {
            cin >> x;
        }
        vector<int> c(k);
        for (int i = 0; i < k; i++) {
            c[i] = d[b[i] - 1];
        }
        sort(c.begin(), c.end());
        int t = 0;
        while (t < k && c[t] == a[t]) {
            t++;
        }
        cout << a[t] << "\n";
    }
    return 0;
}