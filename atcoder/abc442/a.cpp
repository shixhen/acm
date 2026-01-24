#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int cnt = 0;
    for (auto &i : s) {
        if (i == 'i' || i == 'j') cnt++;
    }
    cout << cnt << "\n";
    return 0;
}