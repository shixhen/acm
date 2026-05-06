#include <bits/stdc++.h>


using namespace std;

// ==================== 第一部分：DP求最少次数 ====================

vector<vector<int>> dp(100 + 1, vector<int>(100 + 1, 0));

int minDrops(int eggs, int floors) {
    // dp[e][f] = 用 e 个蛋测 f 层楼的最少次数
    

    // 1个蛋：只能逐层试，f层楼需要f次
    for (int f = 0; f <= floors; f++)
        dp[1][f] = f;

    // 2个及以上蛋：DP
    for (int e = 2; e <= eggs; e++) {
        for (int f = 1; f <= floors; f++) {
            dp[e][f] = INT_MAX;
            for (int x = 1; x <= f; x++) {
                // 在第 x 层扔：
                //   碎了 → 剩 e-1 个蛋，测 x-1 层  → dp[e-1][x-1]
                //   没碎 → 剩 e 个蛋，测 f-x 层    → dp[e][f-x]
                // 最坏情况取 max，再 +1（本次操作）
                int worst = 1 + max(dp[e - 1][x - 1], dp[e][f - x]);
                dp[e][f] = min(dp[e][f], worst);
            }
        }
    }
    return dp[eggs][floors];
}

// ==================== 第二部分：模拟最优策略 ====================

void simulate(int totalFloors, int criticalFloor) {
    int k = minDrops(2, totalFloors);  // 最优最大次数
    cout << "========================================\n";
    cout << "  总楼层: " << totalFloors
         << " | 临界楼层: " << criticalFloor
         << " | 最优最坏次数: " << k << "\n";
    cout << "========================================\n\n";

    int drops = 0;
    int floor = 0;    // 上一个安全楼层
    int step = k;     // 当前步长（递减）

    // ---- 第一个球：递减步长跳跃 ----
    while (floor + step <= totalFloors) {
        int nextFloor = floor + step;
        drops++;
        cout << "  [第" << drops << "次] 球1 从第 " << nextFloor << " 层扔下";

        if (nextFloor >= criticalFloor) {
            // 球1碎了！
            cout << " → 碎了!\n\n";
            // ---- 第二个球：线性搜索 ----
            cout << "  球1碎了，用球2从第 " << (floor + 1)
                 << " 层开始逐层测试:\n";
            for (int f = floor + 1; f < nextFloor; f++) {
                drops++;
                cout << "  [第" << drops << "次] 球2 从第 " << f << " 层扔下";
                if (f >= criticalFloor) {
                    cout << " → 碎了!\n";
                    cout << "\n  ★ 临界楼层 = " << f << "\n";
                    cout << "  ★ 总共扔了 " << drops << " 次\n";
                    return;
                } else {
                    cout << " → 没碎\n";
                }
            }
            // 球2也没碎，说明临界层就是 nextFloor
            cout << "\n  ★ 临界楼层 = " << nextFloor << "\n";
            cout << "  ★ 总共扔了 " << drops << " 次\n";
            return;
        } else {
            cout << " → 没碎\n";
        }

        floor = nextFloor;
        step--;
    }

    // ---- 最高层还没碎：逐层搜索剩余楼层 ----
    cout << "\n  球1到达过第 " << floor << " 层都没碎，逐层搜索剩余楼层:\n";
    for (int f = floor + 1; f <= totalFloors; f++) {
        drops++;
        cout << "  [第" << drops << "次] 球2 从第 " << f << " 层扔下";
        if (f >= criticalFloor) {
            cout << " → 碎了!\n";
            cout << "\n  ★ 临界楼层 = " << f << "\n";
            cout << "  ★ 总共扔了 " << drops << " 次\n";
            return;
        } else {
            cout << " → 没碎\n";
        }
    }

    cout << "\n  所有楼层都没碎，临界楼层 > " << totalFloors << "\n";
}

// ==================== 主函数 ====================


int fac(int x) {
    int res = 1;
    for (int i = 1; i <= x; i++) {
        res *= i;
    }
    return res;
}

int main() {
    // int floors = 100;

    // // 1. 打印DP表格（2个蛋，1~100层）
    // cout << "===== DP计算最少次数 =====\n";
    // cout << "  2个蛋, 1~" << floors << " 层楼的最优次数:\n\n";
    // for (int f : {10, 20, 50, 100}) {
    //     cout << "    " << f << " 层楼 → 最少需要 " << minDrops(2, f) << " 次\n";
    // }
    // cout << "\n";

    // // 2. 打印跳跃计划
    // int k = minDrops(2, floors);
    // cout << "===== 最优跳跃计划 (步长从 " << k << " 递减) =====\n";
    // int pos = 0, step = k;
    // cout << "  球1依次扔: ";
    // while (pos + step <= floors) {
    //     pos += step;
    //     cout << pos;
    //     if (pos + (step - 1) <= floors) cout << " → ";
    //     step--;
    // }
    // cout << "\n\n";

    // // 3. 模拟几个不同的临界楼层
    // for (int cf : {1, 14, 50, 87, 99, 100}) {
    //     simulate(floors, cf);
    //     cout << "\n";
    // }
    minDrops(100, 100);
    for (int i = 1; i <= 100; i++) {
        // if (dp[2][i] > ceil((sqrt(2 * i)))) {
        //     cout << dp[3][i] << " " << (int) sqrt(2 * i) << "\n";
        // }
        cout << dp[3][i] << " " << (int) pow(fac(3) * i, 1.0 / 3.0) << "\n";
    }

    return 0;
}
