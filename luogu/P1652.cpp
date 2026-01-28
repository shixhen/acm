#include <bits/stdc++.h>

using namespace std;

// ================= 配置与常量 =================
constexpr double eps = 1e-8;
const double PI = acos(-1.0);

// 符号函数：控制精度
int dcmp(double x) {
    if (abs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

// ================= 核心结构体 Point =================
struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    // 基础运算符重载
    Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    Point operator*(double k) const { return Point(x * k, y * k); }
    Point operator/(double k) const { return Point(x / k, y / k); }

    // 比较运算符 (用于排序和去重，例如凸包算法)
    // 优先比较 x，x 相同时比较 y
    bool operator<(const Point &p) const {
        return dcmp(x - p.x) < 0 || (dcmp(x - p.x) == 0 && dcmp(y - p.y) < 0);
    }

    bool operator==(const Point &p) const {
        return dcmp(x - p.x) == 0 && dcmp(y - p.y) == 0;
    }

    // --- 常用成员函数 ---

    // 模长平方 (比较长度时推荐用这个，避免 sqrt)
    double len_sq() const { return x * x + y * y; }
    
    // 模长
    double len() const { return sqrt(len_sq()); }

    // 点积 (Dot Product)
    // 几何意义：a·b = |a||b|cosθ
    double dot(const Point &b) const { return x * b.x + y * b.y; }

    // 叉积 (Cross Product)
    // 几何意义：a×b = |a||b|sinθ，代表平行四边形有向面积
    // > 0: b 在 a 的逆时针方向; < 0: b 在 a 的顺时针方向; = 0: 共线
    double cross(const Point &b) const { return x * b.y - y * b.x; }

    // 两点距离
    double dis(const Point &b) const { return (*this - b).len(); }

    // 向量旋转
    // rad 为弧度，逆时针为正
    Point rotate(double rad) const {
        return Point(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
    }
    
    // 绕点 p 旋转
    Point rotate(const Point &p, double rad) const {
        return p + (*this - p).rotate(rad);
    }
    
    // 计算向量的单位法向量 (左旋转90度并归一化)
    Point normal() const {
        double l = len();
        return Point(-y / l, x / l);
    }
};

// 获取象限 (用于极角排序)
// 这里定义：
// 1象限: x>0, y>=0
// 2象限: x<=0, y>0
// 3象限: x<0, y<=0
// 4象限: x>=0, y<0
int get_quad(const Point &p) {
    if (p.x > 0 && p.y >= 0) return 1;
    if (p.x <= 0 && p.y > 0) return 2;
    if (p.x < 0 && p.y <= 0) return 3;
    if (p.x >= 0 && p.y < 0) return 4;
    return 0; // (0,0) 的情况，通常放在最前或最后，看题目要求
}

// 极角排序比较函数 (围绕原点 (0,0))
bool cmp_polar(const Point &a, const Point &b) {
    // 1. 先比较象限
    int qa = get_quad(a);
    int qb = get_quad(b);
    if (qa != qb) return qa < qb;
    
    // 2. 象限相同，使用叉积判断旋转关系
    // 如果 cross(a, b) > 0，说明 b 在 a 的逆时针方向，a 应该排在 b 前面
    double cp = a.cross(b);
    if (dcmp(cp) != 0) return cp > 0;
    
    // 3. (可选) 如果共线 (角度相同)，按距离排序
    // 通常距离近的排前面
    return a.len_sq() < b.len_sq();
}

// ================= 线与线段操作 =================

// 点是否在线段上 (包含端点)
bool on_seg(const Point &p, const Point &a, const Point &b) {
    // 1. 共线 (叉积为0) 且 2. 点在以 ab 为对角线的矩形内 (点积判断)
    return dcmp((b - a).cross(p - a)) == 0 && 
           dcmp((b - a).dot(p - a)) >= 0 && 
           dcmp((a - b).dot(p - b)) >= 0;
}

// 三点共线判定 (修正版：使用叉积)
bool in_line(const Point &a, const Point &b, const Point &c) {
    return dcmp((b - a).cross(c - a)) == 0;
}

// 直线平行判定
bool parallel(const Point &a, const Point &b, const Point &c, const Point &d) {
    return dcmp((b - a).cross(d - c)) == 0;
}

// 直线交点
// 调用前需保证不平行 (或者由题目保证)
Point line_intersection(const Point &a, const Point &b, const Point &c, const Point &d) {
    double u = (a - c).cross(d - c);
    double v = (b - a).cross(d - c);
    // if (dcmp(v) == 0) return Point(NAN, NAN); // 严谨处理平行
    return a + (b - a) * (u / v);
}

// 线段相交判定 (鲁棒版：规范相交 + 非规范相交)
bool seg_intersection(const Point &a, const Point &b, const Point &c, const Point &d) {
    double c1 = (b - a).cross(c - a);
    double c2 = (b - a).cross(d - a);
    double c3 = (d - c).cross(a - c);
    double c4 = (d - c).cross(b - c);

    // 1. 规范相交 (严格跨立，不含端点)
    if (dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0) return true;

    // 2. 非规范相交 (端点重合 或 端点在线段上)
    if (dcmp(c1) == 0 && on_seg(c, a, b)) return true;
    if (dcmp(c2) == 0 && on_seg(d, a, b)) return true;
    if (dcmp(c3) == 0 && on_seg(a, c, d)) return true;
    if (dcmp(c4) == 0 && on_seg(b, c, d)) return true;

    return false;
}

// 点到直线的距离
double point_to_line(const Point &p, const Point &a, const Point &b) {
    return abs((b - a).cross(p - a)) / (b - a).len();
}

// 点到线段的距离
double point_to_seg(const Point &p, const Point &a, const Point &b) {
    if (a == b) return p.dis(a);
    // 点在 a 的外侧
    if (dcmp((b - a).dot(p - a)) < 0) return p.dis(a);
    // 点在 b 的外侧
    if (dcmp((a - b).dot(p - b)) < 0) return p.dis(b);
    // 点在 a, b 之间投影范围内
    return point_to_line(p, a, b);
}

// ================= 多边形操作 =================

// 多边形面积 (Shoelace Formula)
double polygon_area(const vector<Point> &poly) {
    double area = 0;
    int n = poly.size();
    if (n < 3) return 0.0;
    for (int i = 0; i < n; i++) {
        area += poly[i].cross(poly[(i + 1) % n]);
    }
    return abs(area) / 2.0;
}

// 判断点在多边形内 (Winding Number Algorithm - 回转数法)
// 返回值：2: 内部, 1: 边界, 0: 外部
int point_in_polygon(const Point &p, const vector<Point> &poly) {
    int wn = 0;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        Point p1 = poly[i];
        Point p2 = poly[(i + 1) % n];
        
        // 1. 判断是否在边界上
        if (on_seg(p, p1, p2)) return 1; 

        // 2. 计算回转数
        // 叉积 k: p1->p2 向量在 p 的左侧 (>0) 还是右侧 (<0)
        int k = dcmp((p2 - p1).cross(p - p1));
        int d1 = dcmp(p1.y - p.y);
        int d2 = dcmp(p2.y - p.y);

        // 向上穿过射线 (p1 在下方，p2 在上方)
        if (k > 0 && d1 <= 0 && d2 > 0) wn++;
        // 向下穿过射线 (p1 在上方，p2 在下方)
        if (k < 0 && d2 <= 0 && d1 > 0) wn--;
    }
    return wn != 0 ? 2 : 0;
}

// ================= 凸包算法 (Andrew's Monotone Chain) =================
// 求解点集 p 的凸包，结果存入 hull
// 输入点集不需要有序，函数内会排序
// 如果题目要求凸包边上可以有点，把 <= 改为 < 即可
vector<Point> get_convex_hull(vector<Point> &p) {
    int n = p.size();
    if (n <= 2) return p;
    
    // 1. 排序 (基于 operator<)
    sort(p.begin(), p.end());
    
    vector<Point> hull;
    
    // 2. 求下凸壳
    for (int i = 0; i < n; i++) {
        // 当新点在栈顶向量的右侧或共线时，出栈 (维护左转性质)
        while (hull.size() > 1 && 
               dcmp((hull.back() - hull[hull.size() - 2]).cross(p[i] - hull.back())) <= 0) {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }
    
    // 3. 求上凸壳
    int lower_hull_size = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        while (hull.size() > lower_hull_size && 
               dcmp((hull.back() - hull[hull.size() - 2]).cross(p[i] - hull.back())) <= 0) {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }
    
    // 4. 移除重复的起点 (如果是闭合多边形需求)
    if (n > 1) hull.pop_back();
    
    return hull;
}

// ================= 测试用 Main =================
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> cx(n), cy(n), r(n);
    for (auto &x : cx) {
        cin >> x;
    }
    for (auto &x : cy) {
        cin >> x;
    }
    for (auto &x : r) {
        cin >> x;
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Point p1(x1, y1), p2(x2, y2);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        Point c(cx[i], cy[i]);
        double dist1 = (c - p1).len();
        double dist2 = (c - p2).len();
        if ((dcmp(dist1 - r[i]) < 0 && dcmp(dist2 - r[i]) > 0) || (dcmp(dist1 - r[i]) > 0 && dcmp(dist2 - r[i]) < 0)) {
            ans++;
        }
    }
    cout << ans << "\n";
    
    return 0;
}