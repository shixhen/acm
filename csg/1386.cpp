#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int f, x;
    priority_queue<int, vector<int>, greater<int>> q;
    while (n--) {
        cin >> f;
        if (f == 1) {
            cin >> x;
            q.push(x);
        } else {
            cout << q.top() << '\n';
            q.pop();
        }
    }
    return 0;
}