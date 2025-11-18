#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int idx = 0;
    while (s[idx] == s[s.size() - idx - 1] && idx < s.size() - idx - 1) idx++;
    if (idx >= s.size() - idx - 1) {
        cout << 0 <<'\n';
        return;
    }
    s = s.substr(idx, s.size() - idx * 2);
    map<char, int> mp;
    map<char, int> mpl;
    map<char, int> mpr;
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < s.size(); i++) mp[s[i]]++;
    for (int i = 0; i < s.size(); i++) {
        mpl[s[i]]++;
        if (i >= s.size() / 2 && s[i] == s[s.size() - i - 1]) mpl[s[i]]--;
        if (mp[s[i]] < mpl[s[i]] * 2) {
            ans = min(ans, (int) s.size() - i);
            break;
        }
    }
    for (int i = s.size() - 1; i >= 0; i--) {
        mpr[s[i]]++;
        if (i < s.size() / 2 && s[i] == s[s.size() - i - 1]) mpr[s[i]]--;
        if (mp[s[i]] < mpr[s[i]] * 2) {
            ans = min(ans, i + 1);
            break;
        }
    }
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}