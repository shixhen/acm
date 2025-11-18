#include <bits/stdc++.h>

using namespace std;

unsigned int get_hash(string &s) {
    unsigned int h = 0;
    for (auto &c : s) {
        h = h * 31 + c;
    }
    return h;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s(n, 'B');
    cout << s << "\n";
    for (int i = 0; i < n - 1; i++) {
        s[i]--;
        s[i + 1] += 31;
        cout << s << "\n";
        s[i]++;
        s[i + 1] -= 31;
    }
    return 0;
}