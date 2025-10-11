#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    string s;
    while (t--) {
        cin >> s;
        map<int, int> f;
        int idx = 1;
        auto dfs = [&](auto &self, int d) -> void {
            if (s[idx] != '0') {
                f[d * 2] = idx;
                idx++;
                self(self, d * 2);
            } else {
                idx++;
            }
            if (s[idx] != '0') {
                f[d * 2 + 1] = idx;
                idx++;
                self(self, d * 2 + 1);
            } else {
                idx++;
            }
        };
        if (s[0] == '0') {
            cout << "\n";
            continue;
        }
        dfs(dfs, 1);
        cout << s[0];
        for (auto it : f) {
            cout << s[it.second];
        }
        cout << "\n";
    }
}