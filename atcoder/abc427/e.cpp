#include <bits/stdc++.h>

using namespace std;

int h, w;

string change(string &s, int x) {
    string res = s;
    if (x < 0) {
        x = -x;
        // 行变换
        if (x > 1) x++;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') continue;
            if (i + x >= s.size()) {
                res[i] = '2';
                continue;
            }
            if (s[i + x] == '1' && s[i] == '3') return "";
            if (s[i] == '3') continue;
            if (s[i + x] == '1') {
                res[i] = '1';
            } else {
                res[i] = '2';
            }
        }
    } else {
        if (x > 1) x++;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') continue;
            if (i - x < 0) {
                res[i] = '2';
                continue;
            }
            if (s[i] == '3' && s[i - x] == '1') return "";
            if (s[i] == '3') continue;
            if (s[i - x] == '1') {
                res[i] = '1';
            } else {
                res[i] = '2';
            }
        }
    }
    return res;
}

bool check(string &s) {
    for (auto &c : s) {
        if (c == '1') return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> h >> w;
    string s = "";
    for (int i = 1; i <= h; i++) {
        string t;
        s += "0";
        cin >> t;
        for (auto &c : t) {
            if (c == '#') {
                s += '1';
            } else if (c == '.') {
                s += '2';
            } else {
                s += '3';
            }
        }
    }
    s += "0";
    queue<pair<string, int>> q;
    q.push({s, 0});
    set<string> st;
    int d[] = {1, -1, w, -w};
    //cout << s << endl;
    //cout << change(s, -w) << endl;
    while (!q.empty()) {
        auto [u, step] = q.front();
        q.pop();
        if (check(u)) {
            cout << step << "\n";
            return 0;
        }
        if (st.count(u)) continue;
        st.insert(u);
        for (int i = 0; i <= 3; i++) {
            string v = change(u, d[i]);
            if (v == "") continue;
            q.push({v, step + 1});
        }
    }
    cout << -1 << "\n";
    return 0;
}