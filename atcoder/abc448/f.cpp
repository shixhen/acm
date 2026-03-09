#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    struct Q { int x, y, id, bid; };
    vector<Q> q(n);
    int B = 80000;
    int idx = 1;
    for (auto &[x, y, id, bid] : q) {
        cin >> x >> y;
        id = idx++;
        bid = x / B;
    }
    sort(q.begin(), q.end(), [&](Q &a, Q &b) {
        if (a.bid != b.bid) return a.bid < b.bid;
        return (a.bid & 1) ? a.y < b.y : a.y > b.y;
    });
    for (int i = 0; i < n; i++) {
        if (q[i].id == 1) {
            for (int j = i; j < n; j++) cout << q[j].id << ' ';
            for (int j = 0; j < i; j++) cout << q[j].id << ' ';
            break;
        }
    }
}