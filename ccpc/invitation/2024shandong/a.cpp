#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    vector<long long> t(n + 1);
    vector<long long> l(n + 1);
    vector<long long> w(n + 1);
    long long suml = 0, sumt = 0, sumw = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> l[i] >> w[i];
    }
    auto check = [&](long long x) -> bool {
        long long cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += (x / (t[i] * l[i] + w[i])) * l[i];
            if (cnt >= k) {
                return true;
            }
            long long more = x % (t[i] * l[i] + w[i]);
            cnt += min(more / t[i], l[i]);
            if (cnt >= k) {
                return true;
            }
        }
        return cnt >= k;
    };
    long long left = 0, r = LLONG_MAX / 2;
    while (left < r) {
        long long mid = left + (r - left) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << "\n";
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