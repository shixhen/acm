#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--){
        int n;
        cin >> n;
        vector<long long> x(n);
        for (int i = 0; i < n; ++i) cin >> x[i];
        if (n <= 1) {
            cout << 0 << '\n';
            continue;
        }

        int ans = n - 1;               // 最多 n-1 个相切对
        long long L = 0;               // 当前允许的 x 的下界（开区间含义见下）
        long long R = (long long)1e18; // 上界（用很大数代替 +inf）
        long long cur = 0;             // 交替和表达式的当前值
        int fst = 1;                   // 当前段起点的下标（1-based parity 用于奇偶交替判断）

        // 遍历从第二个点到最后一个点（i 表示当前考虑 x[i]）
        for (int i = 1; i < n; ++i){
            // 更新 cur = d_{i} - cur  （注意 x 下标从0，d_i = x[i] - x[i-1]）
            cur = (x[i] - x[i-1]) - cur;

            // 根据 i 的奇偶（相对于起点 fst 的奇偶）去更新 L,R
            if ((i % 2) == (fst % 2)) {
                // 约束形式把 cur 限在右边
                R = min(R, cur);
                if (i < n-1) L = max(L, cur - (x[i+1] - x[i]));
            } else {
                // 约束形式把 cur 限在左边（取负）
                L = max(L, -cur);
                if (i < n-1) R = min(R, (x[i+1] - x[i]) - cur);
            }

            // 如果区间空了，说明从 fst 开始的这段不能再继续连通到 i+1
            if (L >= R) {
                // 必须在 i 与 i+1 之间断开：答案 -1
                --ans;
                // 重置，为下一段重新开始，从 i+1 作为新的起点
                L = 0;
                R = (long long)1e18;
                cur = 0;
                fst = i + 1;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
