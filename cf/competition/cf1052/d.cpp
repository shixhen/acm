#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    int m = 0;
    vector<int> a(r + 1);
    while ((1 << (m)) <= r) m++;

    //cout << m << endl;

    //while (m && (((1 << m) - 1) ^ r) < l) m--;

    //cout << m << endl;
    int num = (1 << m) - 1;
    long long ans = 0;
    num ^= r;
    while (r >= l) {
        for (int i = num; i <= r; i++) {
            ans += (i ^ (r - i + num));
            //cout << i << " " << (r - i + num) << "\n";
            a[i] = (r - i + num);
        }
        r = num - 1;
        m = 0;
        while ((1 << (m)) <= r) m++;

        //while (m && (((1 << m) - 1) ^ r) < l) m--;
        num = (1 << m) - 1;
        num ^= r;
    }
    cout << ans << "\n";
    for (auto &x : a) {
        cout << x << " ";
    }
    cout << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) { solve(); }
    return 0;
}