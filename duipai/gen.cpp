#include <bits/stdc++.h>

using namespace std;

// // 生成 [a, b] 范围内的整数
// std::uniform_int_distribution<int> dist(a, b);

// // 生成 [0, 1) 范围的浮点数
// std::uniform_real_distribution<double> dist(0.0, 1.0);

// 随机排序：
// std::shuffle(vec.begin(), vec.end(), rnd);

// 64位随机数
// mtt19937_64 rnd(time(0));
// std::uniform_int_distribution<long long> dist(1, 1e18);

int main() {
    mt19937 rnd(random_device{}());
    uniform_int_distribution<int> dist(2, 20);
    uniform_int_distribution<int> first_dist(1, 100);
    int t = 10;
    cout << t << "\n";
    //int cnt[11] = {0};
    for (int i = 1; i <= t; i++) {
        int n = dist(rnd);
        int m = dist(rnd);
        cout << n << " " << m << "\n";
        vector<int> a(n);
        for (int i = 1; i < n; i++) {
            uniform_int_distribution<int> dist2(0, a[i - 1] + 1);
            a[i] = dist2(rnd);
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << (i == n - 1 ? "\n" : " ");
        }
    }

    return 0;
}