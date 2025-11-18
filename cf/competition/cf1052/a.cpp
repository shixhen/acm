#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n + 1);
    vector<int> b(n + 1);
    for (auto &x : a) {
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= n; i++) {
        //cout << cnt[i] << " ";
        b[cnt[i]]++;
    }
    //cout << endl;
    int ans = 0;
    int temp = 0;
    for (int i = n; i >= 1; i--) {
        temp += b[i];
        ans =  max(ans, temp * i);
    }
    cout << ans << '\n';
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