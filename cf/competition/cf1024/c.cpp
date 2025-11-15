#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    int i = 0, j = 0;
    int ans = n * n - 1;
    int maxi = n - 1, maxj = n - 1;
    int mini = 0, minj = 0;

    while (mini <= maxi && minj <= maxj) {
        for (j = minj; j <= maxj; j++) {
            a[mini][j] = ans--;
        }
        mini++;

        for (i = mini; i <= maxi; i++) {
            a[i][maxj] = ans--;
        }
        maxj--;

        for (j = maxj; j >= minj; j--) {
            a[maxi][j] = ans--;
        }
        maxi--;

        for (i = maxi; i >= mini; i--) {
            a[i][minj] = ans--;
        }
        minj++;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
           cout <<  a[i][j] << ' ';
        }
        cout << '\n';
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}