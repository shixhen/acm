#include <bits/stdc++.h>

using namespace std;


long long f(long long a, long long b) {
    long long t = a + b;
    long long res = 0;
    while (t) {
        res *= 10;
        res += t % 10;
        t /= 10;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    long long x, y;
    cin >> x >> y;
    vector<long long> a(12);
    a[1] = x;
    a[2] = y;
    for (int i = 3; i <= 10; i++) {
        a[i] = f(a[i - 1], a[i - 2]);
    }
    cout << a[10] << "\n";
    return 0;
}