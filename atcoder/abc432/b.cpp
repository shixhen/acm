#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<int> a;
    string s;
    cin >> s;
    for (char c : s) {
        a.push_back(c - '0');
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != 0) {
            swap(a[0], a[i]);
            break;
        }
    }
    for (int d : a) {
        cout << d;
    }
    cout << '\n';
    return 0;
}