#include <bits/stdc++.h>

using namespace std;

constexpr int N = 100000;

int ask(vector<int>& v) {
    cout << "? ";
    cout << v.size();
    for (auto &i : v) {
        cout << " " << i;
    }
    cout << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    vector<int> a(N, 1);
    int res = ask(a);
    int l = (N - 1) / res + 1;
    int r = N;
    if (res != 1) {
        r = (N - 1) / (res - 1) + 1;
        r--;
    }
    int d = r - l;
    if (d == 0) {
        cout << "! " << l << endl;
        return;
    }
    vector<int> b;
    for (int i = 1; i <= d; i++) {
        b.push_back(l);
        b.push_back(i);
    }
    res = ask(b);
    if (res == 0) {
        cout << "! " << l - 1 << endl;
        return;
    }
    cout << "! " << r - (res - d) << endl;
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
