#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

// 定义 PI
const long double PI = acos(-1.0);

struct Monster {
    long long x, y;
    int id; // 原始编号 1 ~ N
    long double angle;
};

// 叉积
long long cross_product(long long x1, long long y1, long long x2, long long y2) {
    return x1 * y2 - x2 * y1;
}

// 点积
long long dot_product(long long x1, long long y1, long long x2, long long y2) {
    return x1 * x2 + y1 * y2;
}

// 判断两个怪兽是否在同一方向（共线且同向）
bool is_same_direction(const Monster& a, const Monster& b) {
    // 1. 叉积为0说明共线
    // 2. 点积>0说明同向（如果不加这个，相反方向也会被判定为相同）
    return cross_product(a.x, a.y, b.x, b.y) == 0 && dot_product(a.x, a.y, b.x, b.y) > 0;
}

int main() {
    // 优化 I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    // 处理查询
    int Q;
    cin >> Q;
    vector<Monster> monsters(N);
    for (int i = 0; i < N; ++i) {
        cin >> monsters[i].x >> monsters[i].y;
        monsters[i].id = i + 1;
        monsters[i].angle = atan2((long double)monsters[i].y, (long double)monsters[i].x);
    }

    // 按极角排序
    sort(monsters.begin(), monsters.end(), [](const Monster& a, const Monster& b) {
        return a.angle < b.angle;
    });

    // 离散化：将同方向的怪兽聚合
    // ray_counts[k] 表示第 k 个独立方向上有多少怪兽
    vector<int> ray_counts;
    // original_id_to_ray_idx[id] 表示 ID 为 id 的怪兽属于第几个独立方向
    vector<int> original_id_to_ray_idx(N + 1);

    if (N > 0) {
        ray_counts.push_back(1);
        original_id_to_ray_idx[monsters[0].id] = 0;
        
        int current_ray = 0;
        for (int i = 1; i < N; ++i) {
            if (is_same_direction(monsters[i], monsters[i-1])) {
                // 同一方向，计数 +1
                ray_counts[current_ray]++;
            } else {
                // 新方向
                current_ray++;
                ray_counts.push_back(1);
            }
            original_id_to_ray_idx[monsters[i].id] = current_ray;
        }
    }

    // 构建前缀和
    int M = ray_counts.size(); // 独立方向的总数
    vector<int> prefix_sum(M + 1, 0);
    for (int i = 0; i < M; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + ray_counts[i];
    }

    
    for (int i = 0; i < Q; ++i) {
        int a_id, b_id;
        cin >> a_id >> b_id;

        int u = original_id_to_ray_idx[a_id]; // 起点射线索引
        int v = original_id_to_ray_idx[b_id]; // 终点射线索引

        // 这里的索引是按 atan2 逆时针排序的
        // 题目要求顺时针旋转：意味着在数组中我们是向左移动（索引减小）
        
        int ans = 0;

        if (u == v) {
            // 起点和终点在同一方向，不旋转，直接摧毁该方向所有怪兽
            ans = ray_counts[u];
        } else if (v < u) {
            // 顺时针：u -> u-1 -> ... -> v
            // 这种情况下没有跨越 -PI/PI 的分界线
            // 区间是 [v, u]
            ans = prefix_sum[u + 1] - prefix_sum[v];
        } else { // v > u
            // 顺时针：u -> ... -> 0 -> (跨越边界) -> M-1 -> ... -> v
            // 区间是 [0, u] 和 [v, M-1]
            int part1 = prefix_sum[u + 1] - prefix_sum[0]; // [0, u]
            int part2 = prefix_sum[M] - prefix_sum[v];     // [v, M-1]
            ans = part1 + part2;
        }

        cout << ans << "\n";
    }

    return 0;
}