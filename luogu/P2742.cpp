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

// 判断点在多边形内
bool in_polygon(const Point &p, const vector<Point> &poly) {
    int flag = 0;
    for(int i = 0; i < poly.size(); i++) {
        Point p1 = poly[i];
        Point p2 = poly[(i + 1) % poly.size()];
        if(on_seg(p, p1, p2)) return false; // 在边界上
        // k > 0 表示 p 在 p1-p2 的左侧， k < 0 表示 p 在 p1-p2 的右侧
        int k = dcmp((p2 - p1).cross(p - p1));
        int d1 = dcmp(p1.y - p.y);
        int d2 = dcmp(p2.y - p.y);
        // 边的起点在射线下方或同高，终点在射线上方
        if(k > 0 && d1 <= 0 && d2 > 0) flag++;
        // 边的起点在射线上方，终点在射线下方或同高
        if(k < 0 && d2 <= 0 && d1 > 0) flag--;
    }
    return flag != 0;
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
vector<Point> convex_hull(vector<Point> &points) {
    if (points.size() <= 1) return points;

    // 按照 x 坐标排序
    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    vector<Point> hull;
    // 下凸包
    for (const auto &p : points) {
        while (hull.size() >= 2 && dcmp((hull.back() - hull[hull.size() - 2]).cross(p - hull.back())) <= 0) {
            hull.pop_back();
        }
        hull.push_back(p);
    }

    // 上凸包
    size_t lower_size = hull.size();
    for (int i = points.size() - 1; i >= 0; i--) {
        const auto &p = points[i];
        while (hull.size() > lower_size && dcmp((hull.back() - hull[hull.size() - 2]).cross(p - hull.back())) <= 0) {
            hull.pop_back();
        }
        hull.push_back(p);
    }

    // 去除重复的点
    if (hull.size() > 1) {
        hull.pop_back();
    }
    
    return hull;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    return 0;
}