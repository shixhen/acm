#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    int minn = 0x3f3f3f3f;
    long long ans = 0;
    for (auto &i : a) {
        cin >> i;
        minn = min(minn, i);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        c[i] = min(a[i], b[i]);
        ans += c[i];
    }
    char ch;
    int x, v;
    while (q--) {
        cin >> ch;
        cin >> x >> v;
        x--;
        if (ch == 'A') {
            ans -= c[x];
            
            a[x] = v;
            c[x] = min(a[x], b[x]);
            ans += c[x];
        }
        if (ch == 'B') {
            ans -= c[x];
            
            b[x] = v;
            c[x] = min(a[x], b[x]);
            ans += c[x];
        }
        cout << ans << "\n";
    }

    return 0;
}