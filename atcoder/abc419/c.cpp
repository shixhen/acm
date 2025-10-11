#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int x, y, minx = INT_MAX, maxx = 0, miny = INT_MAX , maxy = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
    }
    cout << max((maxx - minx + 1) / 2, (maxy - miny + 1) / 2);
    return 0;
}