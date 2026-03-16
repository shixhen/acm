#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);
void solve() {
    int d;
    cin >> d;
    double r = d / 2.0;
    double area = PI * r * r;
    cout << fixed << setprecision(10) << area << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}