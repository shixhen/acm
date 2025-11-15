#include <bits/stdc++.h>

using namespace std;

map<char, string> mp;

void find(char c) {
    cout << c;
    string s = mp[c];
    if (s[0] != '*') {
        find(s[0]);
    }
    if (s[1] != '*') {
        find(s[1]);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    char ch;
    string s;
    char start;
    cin >> n;
    
    cin >> start;
    cin >> s;
    mp[start] = s;
    n--;
    while (n--) {
        cin >> ch;
        cin >> s;
        mp[ch] = s;
    }
    find(start);
    return 0;
}