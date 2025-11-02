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
    uniform_int_distribution<int> dist(0, 2);
    uniform_int_distribution<int> dist2(1, 20000);
    int n = 10;
    vector<vector<int>> tests;
    ofstream fout("output.txt");

    for (int i = 1; i <= n; i++) {
        vector<int> test;
        for (int j = 1; j <= dist2(rnd); j++) {
            test.push_back(dist(rnd));
        }
        tests.push_back(test);
    }
    fout << tests.size() << "\n";
    for (auto &test : tests) {
        fout << test.size() << "\n";
        for (int j = 0; j < test.size(); j++) {
            fout << test[j];
            if (j < test.size() - 1) {
                fout << " ";
            }
        }
        fout << "\n";
    }
    fout.close();

    

    // for (int i = 1; i <= t; i++) {
    //     int n = dist(rnd);
    //     fout << n << "\n";
    // }
    fout.close();

    return 0;
}