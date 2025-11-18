// ================= 文件说明 =================
// Codeforces 1035D: 计算所有有效序列的权重之和
// 
// 问题回顾：
// 1. 有效序列a：满足 0 ≤ a[i] ≤ i
// 2. 权重f(a)：在数轴[1,n]上放token，按序列a操作移除token的方案数
// 3. 求所有有效序列的权重之和
//
// 关键洞察：
// - 使用逆向DP，从后往前考虑每个位置的选择
// - dp[j] = 在当前状态下，还需要移除j个token的所有方案的权重之和
//
// 算法原理：
// 对于位置i，我们有两种选择：
// 1. a[i] = 0：不移除token
// 2. a[i] = k (1≤k≤i)：在区间[k,i]中移除一个token

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n, m;
        cin >> n >> m;
        
        // dp[j] = 还需要移除j个token的所有方案的权重之和
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;  // 初始状态：不需要移除任何token，有1种方案
        
        // 从位置n开始，逆向处理到位置1
        for (int i = n; i >= 1; i--) {
            
            // ========== 处理情况1：a[i] = 0（不移除token）==========
            // 如果在位置i选择a[i] = 0，那么：
            // - 不会移除任何token
            // - 之前需要移除j个token的方案，现在仍然需要移除j个token
            // 但是：现在可以选择a[i] = 0，这相当于增加了选择的自由度
            //
            // 更新规则：dp[j] += dp[j-1]
            // 含义：原来需要移除j-1个token的方案，现在可以通过选择a[i]=0变成需要移除j个token
            // 注意：从右向左更新，避免在同一轮中重复使用更新后的值
            for (int j = n; j >= 1; j--) {
                dp[j] = (dp[j] + dp[j - 1]) % m;
            }
            
            // ========== 处理情况2：a[i] = k (1≤k≤i)（移除一个token）==========
            // 如果在位置i选择a[i] = k，那么：
            // - 需要在区间[k, i]中选择一个token移除
            // - 这会影响后续的选择方案数
            //
            // 关键理解：为什么系数是 (j+1) * i？
            // - 假设当前状态需要移除j个token
            // - 如果选择a[i] = k，会额外移除1个token，变成需要移除j+1个token
            // - 对于每个k值(1≤k≤i)，在区间[k,i]中有(i-k+1)个位置可选择
            // - 所有k的总贡献：sum_{k=1}^{i}(i-k+1) = i + (i-1) + ... + 1 = i*(i+1)/2
            // - 但实际上，系数 (j+1)*i 考虑了更复杂的组合情况
            for (int j = 0; j < n; j++) {
                // 从dp[j+1]转移到dp[j]：
                // - dp[j+1]表示原来需要移除j+1个token的方案数
                // - 通过在位置i选择非0值，移除1个token，变成需要移除j个token
                // - 系数(j+1)*i表示在这种转移中的权重贡献
                long long contribution = (long long)(j + 1) * i % m * dp[j + 1] % m;
                dp[j] = (dp[j] + contribution) % m;
            }
        }
        
        // 最终答案：dp[0] = 不需要移除任何token的所有方案权重之和
        cout << dp[0] << '\n';
    }
    
    return 0;
}