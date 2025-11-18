#include <bits/stdc++.h>

using namespace std;

constexpr double eps = 1e-8;

int dcmp(double x) {
    if (abs(x) < eps) {
        return 0;
    }
    return x < 0 ? -1 : 1;
}

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator+(const Point &p) const {
        return Point(x + p.x, y + p.y);
    }

    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }

    // 重载*
    Point operator*(double k) const {
        return Point(x * k, y * k);
    }

    bool operator==(const Point &p) const {
        return abs(x - p.x) < eps && abs(y - p.y) < eps;
    }

    double get_len() const {
        return sqrt(x * x + y * y);
    }

    // A · B
    double dot(const Point &b) const {
        return x * b.x + y * b.y;
    }

    // AB × AC
    double cross(const Point &b) const {
        return x * b.y - y * b.x;
    }

    double dis(const Point &b) const {
        return sqrt((*this - b).dot(*this - b));
    }

    // 旋转
    Point rotate(const Point &o, double angle) const {
        return Point(
            o.x + (x - o.x) * cos(angle) - (y - o.y) * sin(angle),
            o.y + (x - o.x) * sin(angle) + (y - o.y) * cos(angle)
        );
    }

};

// 点是否在线段上
bool on_seg(const Point &p, const Point &a, const Point &b) {
    return dcmp((b - a).cross(p - a)) == 0 && dcmp((b - a).dot(p - a)) >= 0 && dcmp((a - b).dot(p - b)) >= 0;
}

// 判断三点是否共线
bool inLine(const Point &a, const Point &b, const Point &c) {
    return dcmp((b - a).dot(c - a)) == 0;
}

// 判断两直线是否平行
bool parallel(const Point &a, const Point &b, const Point &c, const Point &d) {
    return dcmp((b - a).cross(c - d)) == 0;
}

double point_to_line(const Point &p, const Point &a, const Point &b) {
    return fabs((b - a).cross(p - a)) / (b - a).get_len();
}

// 两直线的交点
Point line_cross(const Point &a, const Point &b, const Point &c, const Point &d) {
    double u = (a - c).cross(d - c);
    double v = (b - a).cross(d - c);
    return a + (b - a) * (u / v);
}

// 线段相交
bool seg_cross(const Point &a, const Point &b, const Point &c, const Point &d) {
    return dcmp((b - a).cross(c - a)) * dcmp((b - a).cross(d - a)) <= 0 &&
           dcmp((d - c).cross(a - c)) * dcmp((d - c).cross(b - c)) <= 0;
}

// 点到线段的距离
double point_to_seg(const Point &p, const Point &a, const Point &b) {
    if (dcmp((b - a).dot(p - a)) < 0) {
        return p.dis(a);
    }
    if (dcmp((a - b).dot(p - b)) < 0) {
        return p.dis(b);
    }
    return point_to_line(p, a, b);
}

// 多边形面积
double polygon_area(const vector<Point> &poly) {
    if (poly.size() < 3) return 0.0; // 少于三点无法构成多边形
    double area = 0;
    // 使用叉积计算多边形面积
    // 公式：面积 = 1/2 * |Σ (x_i * y_(i+1) - y_i * x_(i+1))|
    for (int i = 0; i < poly.size(); i++) {
        area += poly[i].cross(poly[(i + 1) % poly.size()]);
    }
    return fabs(area) / 2.0;
}

// 凸包
vector<Point> convex_hull(vector<Point> &p) {
    int n = p.size();
    int k = 0;
    if (n <= 1) return p;
    sort(p.begin(), p.end(), [](const Point &a, const Point &b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    vector<Point> h(2 * n);
    // 下凸包
    for (int i = 0; i < n; i++) {
        while (k >= 2 && dcmp((h[k - 1] - h[k - 2]).cross(p[i] - h[k - 2])) <= 0) {
            k--;
        }
        h[k++] = p[i];
    }
    // 上凸包
    int t = k + 1;
    for (int i = n - 2; i >= 0; i--) {
        while (k >= t && dcmp((h[k - 1] - h[k - 2]).cross(p[i] - h[k - 2])) <= 0) {
            k--;
        }
        h[k++] = p[i];
    }
    h.resize(k - 1); // 去掉最后一个点，因为它是重复的
    return h;
}

// 求凸包周长
double convex_hull_perimeter(const vector<Point> &hull) {
    double perimeter = 0.0;
    for (int i = 0; i < hull.size(); i++) {
        perimeter += hull[i].dis(hull[(i + 1) % hull.size()]);
    }
    return perimeter;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    cout << fixed << setprecision(0) << polygon_area(points);
    return 0;
}