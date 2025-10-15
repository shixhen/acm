#include <bits/stdc++.h>

using namespace std;

int ask(vector<int> &v) {
    cout << "? ";
    cout << v.size() << " ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n + 1);
    vector<int> ans(2 * n + 1);
    vector<int> p1(n + 1);
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    int p = 3;
    for (int i = 1, x; i <= 2 * n - 1; i++) {
        a[i] = ask(v);
        if (a[i] == 0) {
            v.push_back(p++);
            continue;
        } else {
            p1[a[i]] = v.back();
            ans[v.back()] = a[i];
            v.pop_back();
            v.push_back(p++);
        }
    }
    v.clear();
    for (int i = 1; i <= n; i++) {
        if (p1[i]) {
            v.push_back(p1[i]);
        }
    }
    for (int i = 1; i <= 2 * n; i++) {
        if (ans[i]) continue;
        v.push_back(i);
        int x = ask(v);
        if (x) {
            ans[i] = x;
        }
        v.pop_back();
    }
    cout << "! ";
    for (int i = 1; i <= 2 * n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}