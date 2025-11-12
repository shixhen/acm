#include <bits/stdc++.h>

using namespace std;

void solve() {
    long double xb, yb, vx, vy, y1, y2, vy1, vy2, x1, x2, vx1, vx2, t, nt;
    cin >> xb >> yb >> vx >> vy;
    cin >> y1 >> y2 >> vy1 >> vy2;
    cin >> x1 >> x2 >> vx1 >> vx2;
    t = (y2 - y1) / (vy1 + vy2);
    yb = y1 + vy1 * t;
    //cout << t << endl;
    if (vx1 == vx2 && vx1 == 0) {
        nt = (x2 - x1) * 2.0 / abs(vx);
        t -= (int)(t / nt) * nt;
    }
    //cout << t << endl;
    while (t >= 1e-6) {
        if (vx > 0) {
            if (vx < vx2) {
                xb = xb + vx * t;
                break;
            }
            nt = (x2 - xb) / (vx - vx2);
            if (nt >= t) {
                xb = xb + vx * t;
                break;
            }
        } else {
            if (-vx < vx1) {
                xb = xb + vx * t;
                break;
            }
            nt = (xb - x1) / (-vx - vx1);
            if (nt >= t) {
                xb = xb + vx * t;
                break;
            }
        }
        xb = xb + vx * nt;
        t -= nt;
        x1 = x1 - vx1 * nt;
        x2 = x2 + vx2 * nt;
        vx = -vx;
    }
    cout << fixed << setprecision(10) << xb << " " << yb << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}