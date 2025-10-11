#include <bits/stdc++.h>

using namespace std;

vector<int> p;

int manacher(const string &s) {
    int n = s.size() - 1, r = 0, c, ans = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            p[i] = min(r - i, p[(c << 1) - i]);
        } else p[i] = 1;
        while (s[i + p[i]] == s[i - p[i]]) p[i]++;
        if (i + p[i] > r) {
            r = i + p[i];
            c = i;
        }
        ans = max(ans, p[i]);
    }
    return ans - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string a;
    cin >> a;
    string s = "$#";
    for (char c : a) {
        s += c;
        s += "#";
    }
    s += "@";
    p.resize(s.size());
    cout << manacher(s);
    return 0;
}