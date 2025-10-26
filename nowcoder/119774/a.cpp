#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a;
    a.push_back(0);
    set<int> s;
    for (int i = 1; ; i++) {
        a.push_back(i * i);
        s.insert(i * i);
        if (i * i > 4 * n) {
            break;
        }
    }
    int ans = 0;
    for (int i = 1; i < a.size(); i++) {
    }
    return 0;
}