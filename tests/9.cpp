#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1000; // 最大值

int log2_table[N];      // 预处理 log2 值

// 预处理 log 表
void init_log(int n) {
    log2_table[1] = 0;
    for (int i = 2; i <= n; i++) {
        log2_table[i] = log2_table[i / 2] + 1;
    }
}

int main() {
    init_log(N - 1); // 初始化 log2 表
    for (int i  = 0; i < N; i++) {
        if (int (log2(i)) != log2_table[i]) {
            cout << "Error at " << i << ": " << log2(i) << " != " << log2_table[i] << endl;
        }
    }
}