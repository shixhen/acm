#include <bits/stdc++.h>

using namespace std;

vector<int> f;



void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.rbegin(), a.rend());
    long long ans = 0;
    for (int i = 0; i < n; i += 2) {
        ans += a[i];
        if (i + 1 < n) {
            a[i + 1] = 0; 
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