#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int x, y;
    cin >> x >> y;
    cout << (x + y - 1) % 12 + 1 << endl;

    return 0;
}