#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long px, py, qx, qy;
        long long n;
        cin >> n;
        cin >> px >> py >> qx >> qy;
        pair<long long, long long> dis;
        long long x;
        cin >> x;
        n--;
        dis = {x, x};
        while (n--) {
            cin >> x;
            if (x > dis.second) {
                dis.first = x - dis.second;
            } else if (x >= dis.first){
                dis.first = 0;
            } else {
                dis.first -= x;
            }
            dis.second += x;
        }
        //cout << dis.first << "  " << dis.second << "----\n";
        long long d = (px - qx) * (px - qx) + (py - qy) * (py - qy);
        if (d >= dis.first * dis.first and d <= dis.second * dis.second) {
            cout << "Yes\n";
        } else cout << "No\n";
    }
    return 0;
}