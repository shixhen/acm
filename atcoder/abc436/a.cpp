#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    int add = n - s.size();
    while (add--) {
        cout << "o";
    }
    cout << s << "\n";


    return 0;
}