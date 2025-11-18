#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    int n, a;
    while (t--) {
        cin >> n;
        unordered_set<int> s;
        while (n--) {
            cin >> a;
            if (!s.count(a)) cout << a << ' ';
            s.insert(a);
        }
        cout << '\n';
    }
    return 0;
}