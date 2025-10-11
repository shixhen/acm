#include <bits/stdc++.h>

using namespace std;

long long ask(int op, long long k) {
    cout << "? ";
    if (op == 1) {
        cout << 'U';
    } else if (op == 2) {
        cout << 'D';
    } else if (op == 3) {
        cout << 'L';
    } else {
        cout << 'R';
    }
    cout << " " << k;
    long long res;
    cin >> res;
    return res;
}


long long dist(long long x1, long long y1, long long x2, long long y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void solve() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> a(n);
    long long minx = 0;
    long long miny = 0x3f3f3f3f3f3f;
    for (auto &[x, y] : a) {
        cin >> x >> y;
        if (y <= miny) {
            if (y == miny) {
                minx = max(minx, x);
            } else {    
                miny = y;
                minx = x;
            }
        }
    }
    long long res;
    ask(4, 1000000000);
    ask(4, 1000000000);
    ask(2, 1000000000);
    res = ask(2, 1000000000);
    
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
