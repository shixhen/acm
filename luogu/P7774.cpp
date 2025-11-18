#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<bool> mp(365, false);
    vector<int> s;
    int x;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (mp[x]) continue;
        mp[x] = true;
        s.push_back(x);
        for (int k = 0; k < s.size(); k++) {
            int j = s[k];
            temp = (j + x) % 360;
            if (mp[temp]) continue;
            mp[temp] = true;
            s.push_back(temp);
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        cout << (mp[x] ? "YES" : "NO") << '\n';
    }

    return 0;
}