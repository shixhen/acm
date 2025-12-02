#include <iostream>
#include <cmath>

using namespace std;

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    if ((x1 == 1 && y1 == 1) || (x1 == 1 && y1 == 10) || (x1 == 9 && y1 == 1) || (x1 == 9 && y1 == 10)) {
        if ((dx == 1 && dy == 1) || (dy == 2 && dx == 2)) {
            cout << "YES\n";
            return;
        }
    }
    int tx = min(abs(x1 - 1), abs(x1 - 9));
    int ty = min(abs(y1 - 1), abs(y1 - 10));
    if (tx <= 1 && ty <= 1) {
        if ((dy == 2 && dx == 2)) {
            cout << "YES\n";
            return;
        }
    }
    if (dx == 0 || dy == 0) {
        if (dx == 1 || dy == 1) {
            if (x1 == 1 || x1 == 9 || y1 == 1 || y1 == 10) {
                cout << "YES\n";
                return;
            }
            
        }
    }
    cout << "NO\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}