#include <bits/stdc++.h>

using namespace std;

int a[105][105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int r = 0, c = (n - 1) / 2;
    int m = n * n - 1;
    int k = 1;
    a[r][c] = k;
    while (m--) {
        k++;
        if (a[(r - 1 + n) % n][(c + 1) % n] == 0) {
            a[(r - 1 + n) % n][(c + 1) % n] = k;
            r = (r - 1 + n) % n;
            c = (c + 1) % n;
        } else {
            a[(r + 1) % n][c] = k;
            r = (r + 1) % n;
        }
        
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}