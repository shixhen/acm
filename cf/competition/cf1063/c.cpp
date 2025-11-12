#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a1(n + 1), a2(n + 1);
    vector<int> pre1(n + 1, 0x3f3f3f3f), pre2(n + 1);
    vector<int> suf1(n + 1), suf2(n + 1);
    
    vector<int> ans(2 * n + 1, 0x3f3f3f3f);
    for (int i = 1; i <= n; i++) {
        cin >> a1[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a2[i];
    }
    suf1[n] = a2[n];
    suf2[n] = a2[n];
    for (int i = n - 1; i >= 1; i--) {
        suf1[i] = min(suf1[i + 1], a2[i]);
        suf2[i] = max(suf2[i + 1], a2[i]);
    }
    for (int i = 1; i <= n; i++) {
        pre1[i] = min(pre1[i - 1], a1[i]);
        pre2[i] = max(pre2[i - 1], a1[i]);
    }
    int n2 = n;
    auto check = [&] (int l, int r) {
        if (a1[1] < l || a1[1] > r) return false;
        if (a2[n2] < l || a2[n2] > r) return false;
        int ll = 1, rr = n2;
        while (ll < rr) {
            int mid = (ll + rr + 1) >> 1;
            if (pre1[mid] >= l && pre2[mid] <= r) {
                ll = mid;
            } else {
                rr = mid - 1;
            }
        }
        if (suf1[ll] < l || suf2[ll] > r) return false;
        return true;
    };
    long long sum = 0;
    int r = 1;
    n <<= 1; 
    for (int i = 1; i <= n; i++) {
        while (r <= n && !check(i, r)) {
            r++;
        }
        if (r <= n) {
            sum += n - r + 1;
        }
    }
    cout << sum << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}