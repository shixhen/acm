#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    for (int i = 0; i < n; i++) {
        int cnt1 = 0, cnt2 = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                cnt1++;
            } else if (a[j] < a[i]) {
                cnt2++;
            }
        }
        cout << max(cnt1, cnt2) << " ";
    }
    cout << "\n";
    return;
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