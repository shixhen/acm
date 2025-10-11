#include <bits/stdc++.h>

using namespace std;

int a[7];
double b[7];

double get_ans(int x) {
    for (int i = 1; i <= 6; i++) {
        b[i] = 0.0;
        if (a[i] == x) {
            b[i] = a[i];
        }
    }
    double sum = 0;
    for (int i = 1; i <= 6; i++) {
        sum += b[i];
    }
    sum /= 6;
    for (int i = 1; i <= 6; i++) {
        b[i] = max(b[i], sum);
    }
    sum = 0;
    for (int i = 1; i <= 6; i++) {
        sum += b[i];
    }
    sum /= 6;
    for (int i = 1; i <= 6; i++) {
        b[i] = max(b[i], sum);
    }
    sum = 0;
    for (int i = 1; i <= 6; i++) {
        sum += b[i];
    }
    return sum / 6.0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for (int i = 1; i <= 6; i++) cin >> a[i];
    double ans = 0;
    for (int i = 1; i <= 6; i++) {
        ans = max(ans, get_ans(6));
    }
    ans *= 5.0;
    cout << fixed << setprecision(10) << ans << "\n";
    return 0;
}