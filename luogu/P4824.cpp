#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s, t;
    cin >> s >> t;
    vector<int> nxt(t.size());
    for (int i = 1, j = 0; i < t.size(); i++) {
        while (j && t[i] != t[j]) j = nxt[j - 1];
        if (t[i] == t[j]) j++;
        nxt[i] = j;
    }
    stack<pair<char, int>> stk;
    for (int i = 0, j = 0; i < s.size(); i++) {
        while (j && s[i] != t[j]) j = nxt[j - 1];
        if (s[i] == t[j]) j++;
        if (j == t.size()) {
            int n = t.size() - 1;
            while (n--) stk.pop();
            j = stk.empty() ? 0 : stk.top().second;
            continue;
        }
        stk.push({s[i], j});
    }
    string ans;
    while (!stk.empty()) {
        ans += stk.top().first;
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}