#include <bits/stdc++.h>

using namespace std;

int a[100][100];

void dfs(int k) {
    if (k == 0) {
        a[0][0] = 1;
        return;
    }
    dfs(k / 2);
    for (int i = 0; i < k / 2; i++) {
        for (int j = 0; j < k / 2; j++) {
            a[i][j + k / 2] = a[i][j] + k / 2;
            a[i + k / 2][j] = a[i][j] + k / 2;
            a[i + k / 2][j + k / 2] = a[i][j];
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        dfs(n);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}