#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    string s;
    int f = 0;
    int cnt = 0;
    while (n--) {
        cin >> s;
        if (s == "login") f = 1;
        else if (s == "logout") f = 0;
        if (s == "private" && f == 0) {
            cnt++;
        }

    }
    cout << cnt;
    return 0;
}