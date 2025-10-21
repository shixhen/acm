#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> ans(n + 1);
    vector<long long> a(n + 1);
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin() + 1, a.end());
    int l = 1;
    for (int r = n; r >= 1; r--) {
        while (sum - a[r] > a[r]) {
            ans[r - l + 1] = sum;
            sum -= a[l];
            l++;
            if (r - 1 <= l) break;
        }
        if (r - 1 <= l) break;
        sum -= a[r];
        if (l > 1) l--;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) solve();
    return 0;
}