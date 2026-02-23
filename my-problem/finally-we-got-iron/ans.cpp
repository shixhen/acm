#include <bits/stdc++.h>
 
using namespace std;
 
int sum;
int cnt;
 
void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n + 2);
    vector<int> b(n + 2);
    vector<int> c(n + 2);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = b[i - 1];
        c[i] = c[i - 1];
        if (a[i] == 1) {
            b[i]++;
        } else if (a[i] == 2) {
            c[i]++;
        }
    }
    
    a[n + 1] = 2;
    b[n + 1] = b[n];
    c[n + 1] = c[n] + 1;
    int h, p;
    
    auto check = [&](int x) -> bool {
        if (c[x - 1] - c[p - 1] > 0) return false;
        return (b[x - 1] - b[p - 1]) < h;
    };
    for (int i = 1; i <= m; i++) {
        cin >> h >> p;
        if (h > 1000000000) {
            cout << "-1 Argument h exceeded range limit, need [1, 1000000000], found " << h << ".\n";
            continue;
        }
        if (p > n) {
            cout << "-1 Argument p exceeded range limit, need [1, " << n << "], found " << p << ".\n";
            continue;
        }
        int l = p, r = n + 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << l << "\n";
    }
    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
