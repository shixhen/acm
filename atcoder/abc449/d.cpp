#include <bits/stdc++.h>

using namespace std;

int l, r, d, u;


bool f(int x, int y) {
    if (l <= x && x <= r && d <= y && y <= u) {
        return true;
    }
    return false;
}
void solve() {
    
    cin >> l >> r >> d >> u;
    long long ans = 0;
    if (f(0, 0)) {
        ans++;
    }
    for (int i = 2; i <= 2e6; i += 2) {
        if (d <= -i && -i <= u) {
            if (r < -i || l > i) {
                
            } else {
                ans += min(r, i) - max(l, -i) + 1;
            }
        }
        if (d <= i && i <= u) {
            if (r < -i || l > i) {
                
            } else {
                ans += min(r, i) - max(l, -i) + 1;
            }
        }
        if (l <= -i && -i <= r) {
            if (u < -i || d > i) {
                
            } else {
                ans += min(u, i) - max(d, -i) + 1;
            }
        }
        if (l <= i && i <= r) {
            if (u < -i || d > i) {
                
            } else {
                ans += min(u, i) - max(d, -i) + 1;
            }
        }
        if (f(-i, -i)) {
            ans--;
        }
        if (f(i, i)) {
            ans--;
        }
        if (f(-i, i)) {
            ans--;
        }
        if (f(i, -i)) {
            ans--;
        }
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}