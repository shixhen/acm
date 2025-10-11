#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += b[i] - a[i];
        if (i < n - 1) {
            if (b[i] > a[i + 1]) {
                ans -= b[i] - a[i + 1];
            }
        }
    }
    cout << ans;
    return 0;
}