#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    string s;
    cin >> s;
    set<int> ans;
    vector<int> temp(m);
    for (int i = m - 1; i >= 0; i--) {
        cin >> temp[i];
    }
    for (auto &x : temp) {
        ans.insert(x);
        if (mp.count(x + 1)) {
            mp[x] = mp[x + 1];
        } else {
            mp[x] = x + 1;
        }
    }
    int y = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            if (mp.count(y + 1)) {
                mp[y] = mp[y + 1];
            } else {
                mp[y] = y + 1;
            }
            y++;
            ans.insert(y);
            continue;
        }
        if (mp.count(y + 1)) {
            ans.insert(mp[y + 1]);
            if (mp.count(mp[y + 1] + 1)) {
                mp[mp[y + 1]] = mp[mp[y + 1] + 1];
            } else {
                mp[mp[y + 1]] = mp[y + 1] + 1;
            }
            y = mp[mp[y + 1]];
        } else {
            ans.insert(y + 1);
            if (mp.count(y + 2)) {
                mp[y + 1] = mp[y + 2]; 
            } else {
                mp[y + 1] = y + 2;
            }
            y = mp[y + 1];
        }
        //cout << i << "   111   " << y << endl;
    }
    cout << ans.size() << "\n";
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }

    return 0;
}