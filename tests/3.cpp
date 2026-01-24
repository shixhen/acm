#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int m;
    cin >> m;
    vector<long long> a(m + 1);
    vector<long long> b(m + 1);
    long long sum = 0;
    long long sum2 = 0;
    long long max1, max2 = 0;
    for (int i = 0; i < m; i++) { 
        cin >> a[i];
        sum += a[i]; 
        if (a[i]) {
            max1 = i;
        }
    }
    for (int i = 0; i < m; i++) { 
        cin >> b[i];
        sum2 += b[i]; 
        if (b[i]) {
            max2 = i;
        }
    }
    if ((sum - a[0]) == 0 || (sum2 - b[0]) == 0 || max1 + max2 < m) {
        cout << "0\n";
        return;
    }
    long long cnt = 0;
    a[0] = max(a[0], (sum2) - sum + a[0]);
    int j = m - 1;
    while (j > 0 && b[j] == 0) { j--; }
    long long add = -1;
    int low = -1;
    for (int i = 0; i < m; i++) {
        if (a[i] == 0 || i + j < m - 1) continue;
        while (a[i]) {
            if (a[i] == 0 || i + j < m - 1) break;
            long long minn = min(a[i], b[j]);
            a[i] -= minn;
            b[j] -= minn;
            if (i + j >= m) { add = 0; }
            cnt += minn;
            cout << cnt << "\n";
            if (low == -1) low = i;
            while (j > 0 && b[j] == 0) { j--; }
            if (j == 0) { break; }
        }
        if (j == 0) { break; }
    }
    cnt += a[m - 1];
    a[m - 1] = 0;
    int i = low + 1;
    while (a[i] == 0 && i < m) { i++; }
    if (i < m && a[i]) { add = 0; }
    cout << max(cnt + add, 0ll) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}