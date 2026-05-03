#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-12;

struct Point {
    double x, y;
};

struct Circle {
    Point c;
    double r;
};

double dist(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

bool inCircle(Point p, Circle c) {
    return dist(p, c.c) <= c.r + EPS;
}

Circle circleFromTwoPoints(Point a, Point b) {
    Point c = {(a.x + b.x) / 2.0, (a.y + b.y) / 2.0};
    return {c, dist(a, b) / 2.0};
}

double cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

Circle circleFromThreePoints(Point a, Point b, Point c) {
    double ax = a.x, ay = a.y;
    double bx = b.x, by = b.y;
    double cx = c.x, cy = c.y;

    double d = 2.0 * (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));

    Point o;
    o.x = ((ax * ax + ay * ay) * (by - cy) +
           (bx * bx + by * by) * (cy - ay) +
           (cx * cx + cy * cy) * (ay - by)) / d;

    o.y = ((ax * ax + ay * ay) * (cx - bx) +
           (bx * bx + by * by) * (ax - cx) +
           (cx * cx + cy * cy) * (bx - ax)) / d;

    return {o, dist(o, a)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<Point> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y;
    }

    shuffle(p.begin(), p.end(), mt19937(random_device{}()));

    Circle ans = {{0, 0}, -1};

    for (int i = 0; i < N; i++) {
        if (ans.r >= 0 && inCircle(p[i], ans)) continue;

        ans = {p[i], 0};

        for (int j = 0; j < i; j++) {
            if (inCircle(p[j], ans)) continue;

            ans = circleFromTwoPoints(p[i], p[j]);

            for (int k = 0; k < j; k++) {
                if (inCircle(p[k], ans)) continue;

                if (fabs(cross(p[i], p[j], p[k])) < EPS) {
                    // 三点共线时，不存在唯一外接圆
                    // 这种情况下真正的最小圆一定由其中最远的两个点决定
                    Circle c1 = circleFromTwoPoints(p[i], p[j]);
                    Circle c2 = circleFromTwoPoints(p[i], p[k]);
                    Circle c3 = circleFromTwoPoints(p[j], p[k]);

                    Circle best = c1;
                    if (c2.r > best.r) best = c2;
                    if (c3.r > best.r) best = c3;

                    if (inCircle(p[i], best) && inCircle(p[j], best) && inCircle(p[k], best))
                        ans = best;
                } else {
                    ans = circleFromThreePoints(p[i], p[j], p[k]);
                }
            }
        }
    }

    cout << fixed << setprecision(10);
    cout << ans.r << "\n";
    cout << ans.c.x << " " << ans.c.y << "\n";

    return 0;
}
