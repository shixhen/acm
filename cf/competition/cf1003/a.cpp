#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string s;
    while(n--) {
        cin >> s;
        s.pop_back();
        s.pop_back();
        s += "i";
        cout << s << endl;
    }

    return 0;
}