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
    uniform_int_distribution<int> dist(1, 30);
    uniform_int_distribution<int> first_dist(1, 100);
    uniform_int_distribution<int> dist2(1, 100);
    int t = 3;
    cout << t << "\n";
    //int cnt[11] = {0};
    for (int i = 1; i <= t; i++) {
        int n = dist(rnd);
        vector<int> a(n);
        cout << n << "\n";
        int first = first_dist(rnd);
        a[0] = first;
        for (int j = 1; j < n; j++) {
            int delta = dist2(rnd);
            a[j] = a[j - 1] + delta;
        }
        for (int j = 0; j < n; j++) {
            cout << a[j] << (j == n - 1 ? "\n" : " ");
        }
    }

    return 0;
}