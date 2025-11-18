#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    long long ans = 0;
    deque<long long> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    d.push_back(a[1]);
    for (int i = 2; i < n; i++) {
        if (d.back() >= a[i] && a[i] <= a[i + 1]) {
            ans += min(d.back(), a[i + 1]);
            while (d.size() > 1) {
                long long x = d.back();
                d.pop_back();
                if (d.back() >= x && x <= a[i + 1]) {
                    ans += min(d.back(), a[i + 1]);
                } else {
                    d.push_back(x);
                    break;
                }
            } 
        } else {
            d.push_back(a[i]);
        }
    }
    d.push_back(a[n]);
    while (d.size() > 1) {
        if (d.front() <= d.back()) {
            long long x = d.front();
            d.pop_front();
            ans += min(d.front(), d.back());
        } else {
            long long x = d.back();
            d.pop_back();
            ans += min(d.front(), d.back());
        }
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}