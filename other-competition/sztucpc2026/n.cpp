#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
using namespace std;

using ll = long long;
using i128 = __int128;   // 需要编译器支持 128 位整数 (GCC/Clang)

// 向下取整除法 (b > 0)
ll floor_div(ll a, ll b) {
    if (a >= 0) return a / b;
    return (a - b + 1) / b;
}

// 向上取整除法 (b > 0)
ll ceil_div(ll a, ll b) {
    if (a >= 0) return (a + b - 1) / b;
    return a / b;
}

// 判断 val 是否是 p 的镜像坐标 (模 2*mod 等于 p 或 2*mod - p)
bool is_mirror(ll val, ll mod, ll p) {
    ll r = val % (2 * mod);
    if (r < 0) r += 2 * mod;
    return (r == p || r == 2 * mod - p);
}

// 获得所有在 [x_min, x_max] 内的镜像 x 坐标 (针对基准 p, 模长 mod)
vector<ll> get_mirror(ll p, ll mod, ll x_min, ll x_max) {
    vector<ll> res;
    ll two_mod = 2 * mod;
    // 序列 1: p + two_mod * i
    ll i1 = ceil_div(x_min - p, two_mod);
    ll i2 = floor_div(x_max - p, two_mod);
    for (ll i = i1; i <= i2; ++i) {
        res.push_back(p + two_mod * i);
    }
    // 序列 2: -p + two_mod * i
    ll j1 = ceil_div(x_min + p, two_mod);
    ll j2 = floor_div(x_max + p, two_mod);
    for (ll i = j1; i <= j2; ++i) {
        res.push_back(two_mod * i - p);
    }
    return res;
}

// 检查是否穿过内部角落
bool check_corner(ll W, ll H, ll sx, ll sy, ll X, ll Y) {
    ll Dx = X - sx, Dy = Y - sy;
    if (Dx == 0 || Dy == 0) return false;  // 平行于轴，无内部角落
    ll Dx_abs = abs(Dx);
    ll kx = abs(floor_div(X, W));
    ll m_start, m_end, step;
    if (Dx > 0) {
        m_start = 1; m_end = kx; step = 1;
    } else {
        m_start = 0; m_end = -kx + 1; step = -1;
    }
    ll y_min = min(sy, Y), y_max = max(sy, Y);
    for (ll m = m_start; (step > 0 ? m <= m_end : m >= m_end); m += step) {
        i128 diff_x = (i128)m * W - sx;
        if ((diff_x * Dy) % Dx_abs != 0) continue;
        i128 Y_wall = sy + diff_x * Dy / Dx;
        if (Y_wall > y_min && Y_wall < y_max && Y_wall % H == 0) {
            return true;  // 内部角落
        }
    }
    return false;
}

// 检查是否提前击中 S 或 T
bool check_early_hit(ll W, ll H, ll sx, ll sy, ll tx, ll ty, ll X, ll Y) {
    ll Dx = X - sx, Dy = Y - sy;
    ll x_min = min(sx, X), x_max = max(sx, X);
    ll y_min = min(sy, Y), y_max = max(sy, Y);

    if (Dx == 0) {
        // 垂直线段，遍历 y 镜像
        vector<ll> Y_t_cands = get_mirror(ty, H, y_min, y_max);
        for (ll Y_t : Y_t_cands) {
            if (Y_t == Y) continue;                // 终点
            if (is_mirror(sx, W, tx) && is_mirror(Y_t, H, ty)) return true; // 提前击中 T
        }
        vector<ll> Y_s_cands = get_mirror(sy, H, y_min, y_max);
        for (ll Y_s : Y_s_cands) {
            if (Y_s == sy) continue;
            if (is_mirror(sx, W, sx) && is_mirror(Y_s, H, sy)) return true; // 中途经过 S
        }
        return false;
    }

    ll Dx_abs = abs(Dx);

    // 遍历 S 镜像
    vector<ll> X_s_cands = get_mirror(sx, W, x_min, x_max);
    for (ll X_s : X_s_cands) {
        if (X_s == sx) continue;                  // 起点
        i128 diff_x = X_s - sx;
        if ((diff_x * Dy) % Dx_abs != 0) continue;
        i128 Y_s = sy + diff_x * Dy / Dx;
        if (Y_s < y_min || Y_s > y_max) continue;
        if (!is_mirror(Y_s, H, sy)) continue;
        if (X_s == X && Y_s == Y) return true;    // 终点是 S 镜像
        return true;                               // 内部 S 镜像
    }

    // 遍历 T 镜像
    vector<ll> X_t_cands = get_mirror(tx, W, x_min, x_max);
    for (ll X_t : X_t_cands) {
        if (X_t == X) continue;                   // 终点
        i128 diff_x = X_t - sx;
        if ((diff_x * Dy) % Dx_abs != 0) continue;
        i128 Y_t = sy + diff_x * Dy / Dx;
        if (Y_t < y_min || Y_t > y_max) continue;
        if (!is_mirror(Y_t, H, ty)) continue;
        return true;                               // 提前击中 T
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll W, H, sx, sy, tx, ty, k;
    cin >> W >> H >> sx >> sy >> tx >> ty >> k;

    long double ans = 1e30;
    bool found = false;

    // 枚举水平反射次数 kx 和垂直反射次数 ky
    for (ll kx = 0; kx <= k; ++kx) {
        ll ky = k - kx;

        vector<ll> X_list, Y_list;

        if (kx == 0) {
            X_list = {tx};
        } else {
            ll dx = (kx % 2 == 0) ? tx : W - tx;
            X_list.push_back( kx * W + dx);
            X_list.push_back(-kx * W + dx);
        }

        if (ky == 0) {
            Y_list = {ty};
        } else {
            ll dy = (ky % 2 == 0) ? ty : H - ty;
            Y_list.push_back( ky * H + dy);
            Y_list.push_back(-ky * H + dy);
        }

        for (ll X : X_list) {
            for (ll Y : Y_list) {
                // 验证实际反射次数
                if (abs(floor_div(X, W)) + abs(floor_div(Y, H)) != k) continue;

                // 角落检查（终点 & 内部）
                if (X % W == 0 && Y % H == 0) continue;   // 终点恰在角落
                if (check_corner(W, H, sx, sy, X, Y)) continue;

                // 提前击中检查
                if (check_early_hit(W, H, sx, sy, tx, ty, X, Y)) continue;

                // 合法路径，更新最短距离
                long double dist = sqrtl((long double)(X - sx)*(X - sx) + (long double)(Y - sy)*(Y - sy));
                if (dist < ans) {
                    ans = dist;
                    found = true;
                }
            }
        }
    }

    if (!found) {
        cout << -1 << endl;
    } else {
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}