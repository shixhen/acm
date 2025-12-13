#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> s;
    int ans = 0;
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (s.count({x, y}) || s.count({x + 1, y}) || s.count({x, y + 1}) || (s.count({x + 1, y + 1}))) {
            continue;
        } else {
            ans++;
            s.insert({x, y});
            s.insert({x + 1, y});
            s.insert({x, y + 1});
            s.insert({x + 1, y + 1});
        }
    }

    cout << ans << "\n";
    return 0;
}