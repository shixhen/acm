#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (a[n] == a[1] && a[n] == -1) {
        a[n] = 0;
        a[1] = 0;
    } else if (a[n] == -1) {
        a[n] = a[1];
    } else if (a[1] == -1) {
        a[1] = a[n];
    }
    long long sum = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] == -1) {
            a[i] = 0;
        }
        sum += (a[i] - a[i - 1]);
    }
    cout << abs(sum) << "\n";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
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