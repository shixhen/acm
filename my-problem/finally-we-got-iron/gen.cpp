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
    uniform_int_distribution<int> dist(0, 1);
    uniform_int_distribution<int> dist2(1, 200);
    uniform_int_distribution<int> dist3(1, 2000000000);
    int t = 100;
    vector<vector<int>> tests;
    ofstream fout("output.txt");
    fout << t << "\n";
    for (int i = 1; i <= t; i++) {
        vector<int> test;
        int n = 100;
        int m = 20;
        fout << n << " " << m << "\n";
        for (int j = 1; j <= n; j++) {
            fout << dist(rnd);
            if (j < n) {
                fout << " ";
            }
        }
        fout << "\n";
        for (int j = 1; j <= m; j++) {
            fout << dist2(rnd);
            
            fout << " ";
            
            fout << dist2(rnd);

            fout << "\n";
        }
        // for (int j = 1; j <= 10; j++) {
        //     for (int k = 1; k <= 20; k++) {
        //         fout << dist3(rnd);
                
        //         fout << " ";

        //         fout << k;

        //         fout << "\n";
        //     }
            
        // }
    }
    // for (int i = 1; i <= t; i++) {
    //     int n = dist(rnd);
    //     fout << n << "\n";
    // }
    fout.close();

    return 0;
}