#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<string> s(n);
    for (auto &i : s) {
        cin >> i;
    }
    int t;
    string a;
    cin >> t >> a;
    t--;
    if (t < n && t >= 0 && s[t] == a) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}