#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// 解决单个测试用例的函数
void solve() {
    int n;
    int k; 
    cin >> n >> k;

    vector<int> a(n);
    int max_a = 0;
    // 统计 a_i 的频次，用于计算 C_x
    vector<int> a_counts(k + 1, 0); 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= k) {
            a_counts[a[i]]++;
        }
        max_a = max(max_a, a[i]);
    }

    // k' 是实际可能达到的最大卡片数（最大值不能超过 k 或 max_a）
    int k_prime = min(max_a, k);

    if (k_prime == 0) {
        cout << 0 << endl;
        return;
    }

    // 1. 预处理 P_x 和 H(M)
    // Px[x] 存储满足 A_i >= x 的最小 i (1-indexed)
    vector<int> Px(k_prime + 1, n + 1);
    int current_max_a = 0;
    for (int i = 0; i < n; ++i) {
        current_max_a = max(current_max_a, a[i]);
        // 从当前最大值 current_max_a 向下更新 Px
        for (int x = min(current_max_a, k_prime); x >= 1; --x) {
            if (Px[x] <= i + 1) break;
            Px[x] = i + 1;
        }
    }

    // H[M] 存储 max(b_i) = M 时的最大幸福值
    vector<long long> H(k_prime + 1, 0);
    for (int M = 1; M <= k_prime; ++M) {
        H[M] = H[M - 1] + (long long)(n - Px[M] + 1);
    }
    
    // 2. 预处理 C_x (多重背包的物品数量限制)
    // C_x: 至少能携带 x 张卡片的朋友数量
    vector<int> Cx(k_prime + 1, 0);
    // 从 k_prime 开始递减计算，Cx[x] = Cx[x+1] + 满足 a_i = x 的朋友数量
    for (int x = k_prime; x >= 1; --x) {
        Cx[x] = Cx[x + 1] + a_counts[x];
    }
    // 注意：Cx[k_prime+1] 默认为 0，所以边界条件是正确的

    // 3. 动态规划 (多重背包变体 O(k^3))
    // M_S[S]: 形成总和 S 时，使用的元素中最大的值 (M)
    // S=0 时，M=0
    vector<int> M_S(k + 1, 0); 
    // DP[S] 记录总和 S 是否可达
    vector<bool> DP(k + 1, false);
    DP[0] = true;

    // 遍历卡片值 x (物品)
    for (int x = 1; x <= k_prime; ++x) {
        int c = Cx[x]; // 物品 x 的数量限制
        if (c == 0) continue;

        // 朴素多重背包转移 (O(k * k * c) 约 O(k^3))
        // 使用 $x$ 值的卡片
        for (int S = k; S >= x; --S) {
            // 尝试使用 j 张 x
            for (int j = 1; j <= c && S - j * x >= 0; ++j) {
                if (DP[S - j * x]) {
                    // 如果 S - j*x 可达
                    if (!DP[S]) {
                        // 第一次达成 S，最大值 M_S[S] = max(M_S[S - j*x], x)
                        DP[S] = true;
                        M_S[S] = max(M_S[S - j * x], x);
                    } else {
                        // S 已经可达，但我们需要找到最大的 M
                        M_S[S] = max(M_S[S], max(M_S[S - j * x], x));
                    }
                }
            }
        }
    }

    // 4. 找到最大 M
    int M_final_max = 0;
    for (int S = 1; S <= k; ++S) {
        M_final_max = max(M_final_max, M_S[S]);
    }

    // 5. 输出结果
    if (M_final_max == 0) {
        cout << 0 << endl;
    } else {
        cout << H[M_final_max] << endl;
    }
}

int main() {
    // 优化输入输出
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // 考虑到总 k 较小，可以使用 int k
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }

    return 0;
}