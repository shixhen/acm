#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 LIM = 1e12;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int64 x, y, k;
        cin >> x >> y >> k;

        if (y == 1){
            cout << -1 << "\n";
            continue;
        }

        int64 d = y - 1;
        int64 pos = k;

        while (x > 0){
            if (pos > LIM){ pos = LIM + 1; break; }

            int64 t = (pos - 1) / d;  // 当前的 floor((pos-1)/d)
            if (t == 0){
                // 后续操作不会改变 pos
                break;
            }

            int64 R = d * (t + 1);  // 当前 t 段右端点

            // 当前段最多能跳多少次？
            int64 cnt = (R - pos) / t;

            if (cnt >= x){
                // 不需要跳出段，直接在段内完成所有 x 次
                // pos += t * x
                if (pos > LIM - t * x){ pos = LIM + 1; break; }
                pos += t * x;
                x = 0;
                break;
            }

            // 先跳 cnt 次
            pos += t * cnt;
            x -= cnt;

            if (pos > LIM){ pos = LIM + 1; break; }

            // 到了段末端，执行一次操作，进入下一段
            // pos += t
            if (x > 0) {
                if (pos > LIM - t){ pos = LIM + 1; break; }
                pos += t;
                x--;
            }
        }

        if (pos <= LIM) cout << pos << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}
