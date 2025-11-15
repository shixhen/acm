#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s;
    string t;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> s;
        t = "";
        t += s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1]) {
                t += s[i];
            }
        }
        mp[t]++;
    }
    int maxn = 0;
    string ans = "";
    for (auto& it : mp) {
        if (it.second > maxn) {
            maxn = it.second;
            ans = it.first;
        }
    }
    cout << ans << "\n";
    return 0;
}