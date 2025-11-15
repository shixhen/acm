
#include <bits/stdc++.h>

using namespace std;

long long a[200005];
long long b[200005];

int n, m;
int f(long long x) {
    int l = 1, r = m + 1, mid;
    while(l < r) {
        mid = (l + r) >> 1;
        if (b[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}
void solve() {
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long bmax = 0, bmin = 0x3f3f3f3f, _;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        bmin = min(bmin, b[i]);
    }
    b[m + 1] = 0;
    b[0] = 0;
    b[m + 2] = 0;
    sort(b + 1, b + 1 + m);
    long long temp;
    long long last = min(a[1], bmin - a[1]);
    for (int i = 2; i <= n; i++) {
        int p = f(last + a[i]);
        temp = b[p] -a[i];
        if (temp >= last || a[i] >= last) {
            if (temp >= last && a[i] >= last) {
                last = min(temp, a[i]);
            } else if (temp >= last) {
                last = temp;
            } else {
                last = a[i];
            }
        } else {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}