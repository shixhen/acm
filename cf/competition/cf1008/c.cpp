#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> b(n * 2);
    for (auto &i: b) {
        cin >> i;
    }
    sort(b.begin(), b.end());
    cout << b[2 * n - 1];
    long long sum = 0;
    int t = 2 * n - 2;
    for (int i = 0; i < t; i += 2) {
        cout << ' ' << b[i] << ' ' << b[i + 1];
        sum += b[i] - b[i + 1];
    }
    cout << ' ' << b[2 * n - 1] - sum + b[2 * n - 2] << ' ' << b[2 * n - 2] << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}