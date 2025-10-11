#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    stack<int> a;
    int q;
    cin >> q;
    for (int i = 1; i <= 100; i++) {
        a.push(0);
    }
    int f, x;
    while(q--) {
        cin >> f;
        if (f == 1) {
            cin >> x;
            a.push(x);
        } else {
            cout << a.top() << '\n';
            a.pop();
        }
    }
    return 0;
}