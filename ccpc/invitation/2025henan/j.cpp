#include <bits/stdc++.h>

using namespace std;


int cnt[] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i <= 25; i++) {
        int temp = 0;
        for (auto &c : s) {
            temp += cnt[(c - 'A' + i) % 26];
        }
        ans = max(ans, temp);
    }
    cout << ans << "\n";

    return 0;
}