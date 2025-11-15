#include <bits/stdc++.h>

using namespace std;

int a[200005];

bool check(vector<int> a) {
    int n = a.size();
    vector<int> suf_mex(n);
    vector<bool> flag(n + 1, false);
    int mex = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] < n) flag[a[i]] = true;
        while(flag[mex]) mex++;
        suf_mex[i] = mex;
    }
    int minn = a[0];
    for (int i = 0; i < n - 1; i++) {
        minn = min(minn, a[i]);
        if (minn < suf_mex[i + 1]) return false;
    }
    return true;
}

void solve() {
    int n, cnt0 = 0, flag = 1;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b;
    for (int i = 0; i < n; i++) {
        if (a[i]) b.push_back(a[i]);
        else {
            cnt0++; 
            if (flag) {
                b.push_back(0);
                flag = 0;
            } 
        }
    }
    if (cnt0 > 0 && check(b)) cout << n - cnt0 + 1 << '\n';
    else cout << n - cnt0 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}