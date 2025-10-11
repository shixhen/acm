#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a;
    cin >> n;
    if (n == 2) {
        cout << "? 2 1 2" << endl;
        cin >> a;
        if (a) {
            cout << "! ()" << endl;
        } else {
            cout << "! )(" << endl;
        }
        return;
    }
    // 已知左右括号
    vector<int> st(n + 2);
    int left = -1;
    int right = -1;
    cout << "? 3 1 2 3" << endl;
    cin >> a;

    if (a == 1) {
        cout << "? 2 1 3" << endl;
        cin >> a;
        if (a == 1) {
            // (() or ())
            left = 1;
            st[1] = 1;
            right = 3;
            st[3] = 2;
            cout << "? 2 1 2" << endl;
            cin >> a;
            if (a == 1) {
                st[2] = 2;
            }  else {
                st[1] = 1;
            }
        } else {
            // ()( or )()
            cout << "? 2 1 2" << endl;
            cin >> a;
            if (a == 1) {
                st[2] = 2;
                st[1] = 1;
                st[3] = 1;
                left = 1;
                right = 2;
            }  else {
                left = 2;
                right = 3;
                st[1] = 2;
                st[3] = 2;
                st[2] = 1;
            }
        }
    } else {
        cout << "? 2 3 1" << endl;
        if (a == 1) {
            // ))( or )((
            cout << "? 2 2 1" << endl;
            cin >> a;
            if (a) {
                st[1] = 2;
                st[2] = 1;
                st[3] = 1;
                left = 2;
                right = 1;
            } else {
                st[1] = 2;
                st[2] = 2;
                st[3] = 1;
                left = 3;
                right = 1;
            }
        } else {
            // ))) or (((

        }

    }
    if (right != -1) {
        for (int i = 3; i <= n - 1; i++) {
            cout << "? " << left << " " << i << " " << i + 1 << right << endl;
            cin >> a;
            if (a == 2) {
                st[i] = 1;
                st[i + 1] = 2;
            } else if (a == 3) {
                st[i] = 2;
                st[i + 1] = 1;
            } else {
                // )) or ((
            }
        }
    } else {
        
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();


    return 0;
}