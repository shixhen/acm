#include <bits/stdc++.h>

using namespace std;

constexpr double eps = 1e-8;


struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }

    double dot(const Point &b) const {
        return x * b.x + y * b.y;
    }

    double dis(const Point &b) const {
        return sqrt((*this - b).dot(*this - b));
    }


};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<Point> poly(n);
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        poly[i] = Point(x, y);
    }
    double ans = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = min(ans, poly[i].dis(poly[j]));
        }
    }
    cout << fixed << setprecision(4) << ans << "\n";
    return 0;
}