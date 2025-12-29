#include <bits/stdc++.h>

using namespace std;


int a[200];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    int t = __gcd(a[1], a[2]);
    for (int i = 3; i <= n; i++) {
        t = __gcd(t, a[i]);
    }
    cout << t << "\n";
    return 0;
}