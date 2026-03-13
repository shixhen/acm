#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, p;
    cin >> n >> m >> p;
    cout << ((p * m) - (__gcd(n, m) + __gcd(abs(n - p), m) + p)) / 2 + 1;
    return 0;
}