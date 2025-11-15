#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int op, x;
    priority_queue<int, vector<int>, greater<int>> q;
    while (n--) {
        cin >> op;
        if (op == 1) {
            cin >> x;
            q.push(x);
        } else if (op == 2) {
            cout << q.top() << "\n";
        } else {
            q.pop();
        }
    }
}