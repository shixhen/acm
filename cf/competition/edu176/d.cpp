#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long x, y;
    cin >> x >> y;
    string a, b;
    int alen, blen;
    long long temp = x;
    while (temp > 0) {
        a += ('0' + (temp & 1));
        temp >>= 1; 
    }
    reverse(a.begin(), a.end());
    temp = y;
    while (temp > 0) {
        b += ('0' + (temp & 1));
        temp >>= 1; 
    }
    reverse(b.begin(), b.end());
    int i;
    for (i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] != b[i]) break;
    }
    vector<long long> t(100);
    for (int j = 1; j <= 70; j++) {
        t[j] = j;
    }
    for (int j = 1; j <= 70; j++) {
        t[j] += t[j - 1];
    }
    int t1 = a.size();
    int t2 = b.size();
    if (t1 < t2) swap(t1, t2);
    int j = 1;
    long long ans = 0;
    while (t1 > 0 || t2 > 0) {
        if (t1 == t2 && t1 <= i) break;
        if (t1 > t2) swap(t1, t2);
        if (t1 <= i) swap(t1, t2);
        t1 -= j;
        ans += 1 << j;
        j++;
    }
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}