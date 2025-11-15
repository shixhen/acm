#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<bool> st(n + 1);
    int cnt = 0;
    int j = 1;
    int num = 0;
    while (1) {
        if (st[j]) {
            j++;
            if (j > n) j = 1;
            continue;
        }
        cnt++;
        if (cnt == m) {
            st[j] = 1;
            num++;
            cout << j << " \n"[num == n];
            if (num == n) break;
            cnt = 0;
        }
        j++;
        if (j > n) j = 1;
    }
    return 0;
}