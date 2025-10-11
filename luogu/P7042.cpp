#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    vector<ll> a(4);
    ll x;
    cin >> t;
    while (t--) {
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        x = __gcd(a[0], a[1]);
        x = __gcd(x, a[2]);
        x = __gcd(x, a[3]);
        sort(a.begin(), a.end());
        for (auto &i : a) {
            i /= x;
        }
        if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) {
            cout << "1\n";
        } else if (a[0] + a[3] != a[1] + a[2]) {
            cout << "0\n";
        } else if (a[0] == a[1] || a[1] == a[2]) {
            cout << "4\n";
        } else {
            cout << "8\n";
        }
    } 
    
}