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

    bool operator==(const Point &p) const {
        return abs(x - p.x) < eps && abs(y - p.y) < eps;
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

// 判断三点是否共线
bool inLine(const Point &a, const Point &b, const Point &c) {
    return dcmp((b - a).dot(c - a)) == 0;
}

// 判断两直线是否平行
bool parallel(const Point &a, const Point &b, const Point &c, const Point &d) {
    return dcmp((b - a).cross(c - d)) == 0;
}





int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    return 0;
}