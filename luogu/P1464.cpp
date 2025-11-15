#include <bits/stdc++.h>

using namespace std;

long long f[25][25][25];
long long w(long long a, long long b, long long c) {
    if (a <= 0 or b <= 0 or c <= 0) return f[0][0][0] = 1;
    if (a > 20 or b > 20 or c > 20) {
        if (f[20][20][20] == 0x3f3f3f3f3f3f3f3f) return f[20][20][20] = w(20, 20, 20);
        else return f[20][20][20];
    }
    if (f[a][b][c] != 0x3f3f3f3f3f3f3f3f) return f[a][b][c];
    if (a < b and b < c) return f[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    return f[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}


int main() {
    memset(f, 0x3f, sizeof(f));
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    long long a, b, c;
    cin >> a >> b >> c;
    while (a != -1 or b != -1 or c != -1) {
        cout << "w(" << a <<", " << b << ", " <<  c  << ") = " << w(a, b, c) << '\n';
        cin >> a >> b >> c;
    }

    return 0;
}