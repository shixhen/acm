#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

Point operator-(const Point& a, const Point& b) {
    return {a.x - b.x, a.y - b.y};
}

long long cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

long long cross(const Point& a, const Point& b, const Point& c) {
    // (b-a) x (c-a)
    return cross(b - a, c - a);
}

long long dist2(const Point& a, const Point& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx * dx + dy * dy;
}

vector<Point> convexHull(vector<Point> p) {
    sort(p.begin(), p.end());
    int n = (int)p.size();
    vector<Point> h;
    h.reserve(2 * n);

    // lower hull
    for (int i = 0; i < n; i++) {
        while ((int)h.size() >= 2 &&
               cross(h[(int)h.size() - 2], h.back(), p[i]) <= 0) {
            h.pop_back();
        }
        h.push_back(p[i]);
    }

    // upper hull
    int t = (int)h.size();
    for (int i = n - 2; i >= 0; i--) {
        while ((int)h.size() > t &&
               cross(h[(int)h.size() - 2], h.back(), p[i]) <= 0) {
            h.pop_back();
        }
        h.push_back(p[i]);
    }

    if (!h.empty()) h.pop_back(); // remove duplicated first point
    return h;
}

long long diameter2(const vector<Point>& h) {
    int m = (int)h.size();
    if (m == 1) return 0;
    if (m == 2) return dist2(h[0], h[1]);

    long long ans = 0;
    int j = 1;

    for (int i = 0; i < m; i++) {
        int ni = (i + 1) % m;
        // move j while area increases
        while (cross(h[ni] - h[i], h[(j + 1) % m] - h[j]) > 0) {
            j = (j + 1) % m;
        }
        ans = max(ans, dist2(h[i], h[j]));
        ans = max(ans, dist2(h[ni], h[j]));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    vector<Point> hull = convexHull(p);
    cout << diameter2(hull) << '\n';
    return 0;
}