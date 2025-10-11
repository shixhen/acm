#include <bits/stdc++.h>

using namespace std;


char a1, a2;
int d1, d2;
void dfs1(string &s, int d) {
    char r = s[0];
    s = s.substr(1);
    if (r != '#') {
        dfs1(s, d + 1);
        dfs1(s, d + 1);
        if (d >= d1) {
            
            if (d1 == d) {
                a1 = min(a1, r);
            } else {
                a1 = r;
            }
            d1 = d;
        }
    }
}

void dfs2(string &s, int d) {
    char r = s[0];
    s = s.substr(1);
    if (r != '#') {
        dfs2(s, d + 1);
        dfs2(s, d + 1);
        if (d >= d2) {
            
            if (d2 == d) {
                a2 = min(a2, r);
            } else {
                a2 = r;
            }
            d2 = d;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        d1 = d2 = 0;
        a1 = a2 = 'z' + 1;
        string s;
        cin >> s;
        s = s.substr(1);
        dfs1(s, 1);
        dfs2(s, 1);
        if (a1 > a2) swap(a1, a2);
        cout << d1 + d2 << ":" << a1 << " " << a2 << "\n"; 
    }
    return 0;
}