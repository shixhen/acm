#include <bits/stdc++.h>

using namespace std;

string mid;
string after;

void beford(string mid, string after) {
    if (mid.size() > 0) {
        char ch = after[after.size() - 1];
        cout << ch;
        int k = mid.find(ch);
        beford(mid.substr(0, k), after.substr(0, k));
        beford(mid.substr(k + 1), after.substr(k, mid.size() - k - 1));
    }
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> mid;
    cin >> after;
    beford(mid, after);
    return 0;
}