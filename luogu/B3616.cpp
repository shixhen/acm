#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    queue<int> q;
    int n;
    cin >> n;
    int f, x;
    while (n--) {
        cin >> f;
        if (f == 1) {
            cin >> x;
            q.push(x);
        } else if (f == 2) {
            if (q.size()) q.pop();
            else cout << "ERR_CANNOT_POP\n";

        } else if (f == 3) {
            if (q.size()) cout << q.front() << '\n';
            else cout << "ERR_CANNOT_QUERY\n";
        } else {
            cout << q.size() << '\n';
        }
    }
    return 0;
}