#include <bits/stdc++.h>

using namespace std;

int ask(const string &s) {
    cout << "? ";
    cout << s << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t, n, x, y;
    cin >> t;
    while (t--) {
        cin >> n;
        string s = "1";
        if (ask(s) == 0) {
            s = "0";
        }
        while (1) {
            if (s.size() == n) {
                break;
            }
            x = ask(s + '1');
            if (x) {
                s += '1';
            }
            if (s.size() == n) {
                break;
            }
            y = ask(s + '0');

            if (y) {
                s += '0';
            }
            if (s.size() == n) {
                break;
            }
            if (x == 0 and y == 0) {
                break;
            }
        }
        if (s.size() == n) {
            cout << "! " << s << endl;
            continue;
        }
        while (1) {
            x = ask('0' + s);
            if (x) {
                s = '0' + s;
            } else {
                s = '1' + s;
            }
            if (s.size() == n) {
                break;
            }
        }
        cout << "! " << s << endl;
    }
    return 0;
}