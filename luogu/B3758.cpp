#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    char ch;
    int cnt = 0;
    while (cin >> ch) {
        if (ch == '(') {
            cnt++;
            cout << '(';
        } else {
            if (cnt) {
                cnt--;
                cout << ')';
            } else {
                cout << "()";
            }
        }
    }
    while (cnt--) {
        cout << ')';
    }
    return 0;
}