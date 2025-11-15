#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-6;

int n;
double a[15];

double f(double x) {
    double s = 0;
    for (int i = 0; i <= n; i++) {
        s = s * x + a[i];
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    double l, r;
    cin >> n >> l >> r;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    double k;
    double mid1, mid2;
    while (r - l > eps) {
        k = (r - l) / 3.0;
        mid1 = l + k, mid2 = r - k;
        if (f(mid1) > f(mid2)) r = mid2;
        else l = mid1;
    }
    cout << fixed << setprecision(5) << l;
    return 0;
}