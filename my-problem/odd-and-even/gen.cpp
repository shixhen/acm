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
    //uniform_int_distribution<int> dist(1000, 2000);
    //uniform_int_distribution<int> first_dist(1, 100);
    //uniform_int_distribution<int> dist2(1, 100);
    int sum = 200000;
    // 输出到文件
    uniform_int_distribution<int> dist(10000, 200000);
    vector<int> a;
    while (a.size() < 10000 && sum > 0) {
        int n = dist(rnd);
        sum -= n;
        if (sum < 0) {
            sum += n;
            a.push_back(sum);
            break;
        }
        a.push_back(n);
        
    }
    ofstream fout("output.txt");
    fout << a.size() << "\n";
    for (int x : a) {
        fout << x << "\n";
    }
    fout.close();

    

    // for (int i = 1; i <= t; i++) {
    //     int n = dist(rnd);
    //     fout << n << "\n";
    // }
    fout.close();

    return 0;
}