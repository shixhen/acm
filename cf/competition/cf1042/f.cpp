#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<long long> ca(n + 2);
    vector<long long> cb(n + 2);
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            ca[i + 1]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (b[i] == '1') {
            cb[i + 1]++;
        }
    }
    long long sum = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ca[i] += ca[i - 1];
        cb[i] += cb[i - 1];
        
    }
    for (int i = 1; i <= n; i++) {
        sum +=(long long) ca[i] + cb[i];
    }
    sum *= n;
    for (int i = 1; i <= n; i++) {
        ca[i] = 2ll * ca[i] - i;
        cb[i] = 2ll * cb[i] - i;
        ans += (long long) ca[i] + cb[i];
    }

    cout << sum  << "\n";
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