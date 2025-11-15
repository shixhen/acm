#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    long long sum = 0;
    long long t = sqrt(sum);
    for (int i = 1; i <= n; i++) {
        sum += i;
        t = sqrt(sum);
        if (t * t == sum && i != n) {
            swap(a[i], a[i + 1]);
        }
    }
    t = sqrt(sum);
    if (t * t == sum) {
        cout << -1 << '\n';
        return;
    } else {
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " \n"[i == n];
        }
    }
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