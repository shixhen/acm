#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<string> a;
    string s;
    while (n--) {
        cin >> s;
        a.push_back(s);
    }
    sort(a.begin(), a.end());
    cin >> s;
    for (auto &x : a) {
        if (x.find(s) == 0) {
            cout << x << "\n";
        }
    }
    return 0;
}