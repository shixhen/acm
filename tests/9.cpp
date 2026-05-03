#include <bits/stdc++.h>

using namespace std;

bool can(long long t, long long m, long long n) {
    int sum = 0;
long long c = 1;  // 当前组合数 C(t, i)

    for (long long i = 1; i <= m && i <= t; ++i) {
        // 递推计算 C(t, i) = C(t, i-1) * (t - i + 1) / i
        c = c * (t - i + 1) / i;
        sum += c;
        if (sum >= n) return true;
    }
    return sum >= n;
}

long long minTests(long long n, long long m) {
    long long l = 0, r = n;   // 1个玻璃最坏要试 n 次，所以答案不会超过 n
    while (l < r) {
        long long mid = l + (r - l) / 2;
        if (can(mid, m, n)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    cout << minTests(n, m) << '\n';
    return 0;
}

// 10000000000000000

/*

1000000000
998265706
*/