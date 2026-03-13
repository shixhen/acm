#include <bits/stdc++.h>    


using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        auto check = [&] (long long x) {
            long long sum = 0;
            // // 偶数
            // if (x & 1) {
            //     sum = (x + 1) * (x + 1);
            // }
            // // 奇数
            // else {
            //     sum = (x + 2) * x + 1;
            // }
            // 可以发现奇偶相等
            sum = (x + 1) * (x + 1);
            return sum >= n;
        };
        // 注意范围，不能计算时不能超过long long范围
        long long l = 0, r = 1e9, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << l << "\n";
    }

    return 0;
}