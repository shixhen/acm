#include <bits/stdc++.h>

using namespace std;

void solve() { 
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (sum - i + (a[i] - 1) >= (n - i - 1) * k) {
            ans = min(ans, sum + 1 + max(0, (n - i - 1) * k - (sum - i)));
        }
        sum += a[i];
    }
    cout << ans << "\n";
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