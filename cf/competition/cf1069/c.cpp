#include <bits/stdc++.h>

using namespace std;


void solve() {
    string s, t;
    cin >> s >> t;
    vector<int> cnts(26);
    vector<int> cntt(26);
    for (int i = 0; i < (int)s.size(); i++) {
        cnts[s[i] - 'a']++;
    }
    for (int i = 0; i < (int)t.size(); i++) {
        cntt[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (cnts[i] > cntt[i]) {
            cout << "Impossible\n";
            return;
        }
        cntt[i] -= cnts[i];
    }
    int j = 0;
    for (auto &c : s) {
        while (j < 26 && cntt[j] == 0) {
            j++;
        }
        while (j < 26 && j < c - 'a') {
            cout << (char)(j + 'a');
            cntt[j]--;
            while (j < 26 && cntt[j] == 0) {
                j++;
            } 
        }
        cout << c;
    }
    for (; j < 26; j++) {
        while (cntt[j] > 0) {
            cout << (char)(j + 'a');
            cntt[j]--;
        }
    }
    cout << "\n";
    return;
}

int main() {
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }

    return 0;
}