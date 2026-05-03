#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;   // n层，m个玻璃

    // f[t][k]：t次机会，k个玻璃，最多能测多少层
    vector<vector<long long>> f(1, vector<long long>(m + 1, 0));

    int T = 0;
    while (f[T][m] < n) {
        ++T;
        f.push_back(vector<long long>(m + 1, 0));
        for (int k = 1; k <= m; ++k) {
            long long val = f[T - 1][k - 1] + f[T - 1][k] + 1;
            if (val > (long long)4e18) val = (long long)4e18;
            f[T][k] = val;
        }
    }
    cout << f[13][1] << "\n";
    int L = 1, R = n;
    int t = T, k = m;

    while (L <= R && t > 0 && k > 0) {
        long long step = f[t - 1][k - 1] + 1;
        int pos = (int)min<long long>(L + step - 1, R);

        cout << pos << endl;   // 输出要扔的楼层
        cout.flush();          // 交互时必须刷新

        int broken;
        cin >> broken;         // 你输入 0 或 1

        if (broken) {
            // 碎了，说明答案在 [L, pos-1]
            R = pos - 1;
            --k;
        } else {
            // 没碎，说明答案在 [pos+1, R]
            L = pos + 1;
        }

        --t;
    }

    // 这里 L 就是答案（第一个会碎的楼层）
    cout << "answer " << L << endl;
    cout.flush();

    return 0;
}