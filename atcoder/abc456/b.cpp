#include <bits/stdc++.h>

using namespace std;

int a[7], b[7], c[7];


double cnt(int x, int d[]) {
    int res = 0;
    for (int i = 1; i <= 6; i++) {
        if (d[i] == x) {
            res++;
        }
    }
    return  (double) res / 6.0;
}

int main() {
    for (int i = 1; i <= 6; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= 6; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= 6; i++) {
        cin >> c[i];
    }
    double ans1 = cnt(4, a) * cnt(5, b) * cnt(6, c);
    double ans4 = cnt(4, a) * cnt(6, b) * cnt(5, c);
    double ans2 = cnt(5, a) * cnt(6, b) * cnt(4, c);
    double ans5 = cnt(5, a) * cnt(4, b) * cnt(6, c);
    double ans3 = cnt(6, a) * cnt(4, b) * cnt(5, c);
    double ans6 = cnt(6, a) * cnt(5, b) * cnt(4, c);
    double ans = ans1 + ans2 + ans3 + ans4 + ans5 + ans6;
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}