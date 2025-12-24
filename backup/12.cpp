#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

long long dp[20][20];
vector<int> num;
int target_digit;

// dfs(pos, cnt, tight, lead_zero)
// pos: 当前处理的位置（从左到右）
// cnt: 到目前为止，目标数字出现的次数
// tight: 是否受到 n 的大小限制（例如，n=123，处理到第2位时，如果第1位填了1，则第2位最大只能填2）
// lead_zero: 当前是否是前导零（例如，n=123，我们不想统计像 007 这样的数字）
long long dfs(int pos, int cnt, bool tight, bool lead_zero) {
    if (pos == num.size()) {
        return cnt;
    }
    // 记忆化：如果状态已经计算过，直接返回结果
    if (!tight && !lead_zero && dp[pos][cnt] != -1) {
        return dp[pos][cnt];
    }

    long long ans = 0;
    int up = tight ? num[pos] : 9; // 当前位能填的最大数字

    for (int i = 0; i <= up; ++i) {
        if (lead_zero && i == 0) {
            // 如果是前导零，数字还没真正开始，继续向下一位搜索
            ans += dfs(pos + 1, cnt, tight && (i == up), true);
        } else {
            // 数字开始了，正常计数
            ans += dfs(pos + 1, cnt + (i == target_digit), tight && (i == up), false);
        }
    }

    if (!tight && !lead_zero) {
        dp[pos][cnt] = ans;
    }
    return ans;
}

// 计算在 [1, n] 区间内，数字 d 出现的次数
long long solve(long long n, int d) {
    if (n <= 0) return 0;
    
    num.clear();
    long long temp = n;
    while (temp) {
        num.push_back(temp % 10);
        temp /= 10;
    }
    reverse(num.begin(), num.end());

    target_digit = d;
    memset(dp, -1, sizeof(dp));
    return dfs(0, 0, true, true);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    cin >> a >> b;

    for (int d = 0; d <= 9; ++d) {
        long long ans_b = solve(b, d);
        long long ans_a_minus_1 = solve(a - 1, d);
        cout << ans_b - ans_a_minus_1 << (d == 9 ? "" : " ");
    }
    cout << endl;

    return 0;
}