#include <bits/stdc++.h>

using namespace std;

char s[105][105];
char temp[105][105];
char tar[105][105];
int n;
int check() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j] != tar[i][j]) {
                res++;
            }
        }
    }
    return res;
}

void change() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            temp[i][j] = s[n - j + 1][i];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] = temp[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> s[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> tar[i][j];
        }
    }
    int ans = 1e9;
    int t = 0;
    ans = min(check() + t, ans);
    t++;
    change();
    ans = min(check() + t, ans);
    t++;
    change();
    ans = min(check() + t, ans);
    t++;
    change();
    ans = min(check() + t, ans);
    cout << ans;
    return 0;
}