#include <bits/stdc++.h>

using namespace std;

constexpr int c = 'a' - 'A';


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    string s;
    cin >> n;
    map<string, int> mp;
    while (n--) {
        cin >> s;
        for (auto &i : s) {
            if (i >= 'A' && i <= 'Z') {
                i += c;
            }
            if (i == '@') i = 'a';
            if (i == '0') i = 'o';
        }
        mp[s]++;
    }
    long long ans = 0;
    for (auto [_, cnt] : mp) {
        ans += 1ll * cnt * (cnt - 1) / 2;
    }
    cout << ans << "\n";
    return 0;
}