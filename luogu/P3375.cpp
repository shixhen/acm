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
    for (int i = 0, j = 0; i < s.size(); i++) {
        while (j && s[i] != t[j]) j = nxt[j - 1];
        if (s[i] == t[j]) j++;
        if (j == t.size()) {
            cout << i - t.size() + 2 << '\n';
            j = nxt[j - 1];
        }
    }
    for (int i = 0; i < nxt.size(); i++) {
        cout << nxt[i] << " \n"[i == nxt.size() - 1];
    }
    return 0;
}