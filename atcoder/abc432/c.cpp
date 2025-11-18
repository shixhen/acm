#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long long n, x, y;
    cin >> n >> x >> y;
    vector<long long> a(n + 1);
    long long minn = 0x3f3f3f3f3f;
    long long maxn = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        minn = min(minn, a[i]);
        maxn = max(maxn, a[i]);
    }
    if (maxn * x > minn * y) {
        cout << "-1\n";
        return 0;
    }
    long long tot = minn * y;
    //cout << tot << '\n';
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        if ((tot - a[i] * x) % (y - x) != 0) {
            cout << "-1\n";
            return 0;
        }
        sum += (tot - a[i] * x) / (y - x);
    }
    cout << sum << '\n';
    return 0;
}