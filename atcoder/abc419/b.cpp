#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int qq;
    cin >> qq;
    int op, x;
    priority_queue<int, vector<int>, greater<int>> q;
    while (qq--) {
        cin >> op;
        if (op == 1) {
            cin >> x;
            q.push(x);
        } else {
            cout << q.top() << "\n";
            q.pop();
        }
    }
    return 0;
}