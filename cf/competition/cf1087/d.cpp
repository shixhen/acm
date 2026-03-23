#include <bits/stdc++.h>

using namespace std;


int r, g, b;


int get(char c) {
    if (c == 'R') {
        return r;
    } else if (c == 'G') {
        return g;
    } else {
        return b;
    }
}

void reset(char c) {
    if (c == 'R') {
        r = 0;
    } else if (c == 'G') {
        g = 0;
    } else {
        b = 0;
    }
}

void setv(char c, int cnt) {
    if (c == 'R') {
        r = cnt;
    } else if (c == 'G') {
        g = cnt;
    } else {
        b = cnt;
    }
}

bool ismax(char c) {
    if (c == 'R') {
        return r >= g && r >= b;
    } else if (c == 'G') {
        return g >= r && g >= b;
    } else {
        return b >= r && b >= g;
    }
}

void solve() {
    
    cin >> r >> g >> b;
    auto can = [&] () {
        if (r == 0 && g == 0 && b == 0) {
            return 'T';
        }
        if (r >= g && r >= b) {
            return 'R';
        }
        if (g >= r && g >= b) {
            return 'G';
        }
        if (b >= r && b >= g) {
            return 'B';
        }
    };
    string s;
    while (r > 0 || g > 0 || b > 0) {
        if (s.size() >= 2) {
            if (ismax(s[s.size() - 2]) && get(s[s.size() - 2]) != 0) {
                char c = s[s.size() - 2];
                s += c;
                if (c == 'R') {
                    r--;
                } else if (c == 'G') {
                    g--;
                } else {
                    b--;
                }
                continue;
            }
        }
        char last;
        int lcnt = 0;
        char second_last;
        int secnt = 0;
        if (!s.empty()) {
            last = s.back();
            lcnt = get(last);
            reset(last);
        }
        if (s.size() >= 3) {
            second_last = s[s.size() - 3];
            secnt = get(second_last);
            reset(second_last);
        }
        char c = can();
        if (c == 'T') {
            break;
        }
        if (!s.empty()) {
            setv(last, lcnt);
        }
        if (s.size() >= 3 && second_last != last) {
            setv(second_last, secnt);
        }
        if (c == 'R') {
            s += "R";
            r--;
        } else if (c == 'G') {
            s += "G";
            g--;
        } else {
            s += "B";
            b--;
        }
    }
    cout << s << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}