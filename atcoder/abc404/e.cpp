#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    n--;
    long long ans = 0;
    vector<long long> temp(n + 1);
    vector<long long> c(n + 1);
    vector<long long> a(n + 1);
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        temp[i] = 0x3f3f3f3f3f;
    }
    for (int i = 1; i <= n; i++) {
        long long minn = 0x3f3f3f3f3f;
        int idx = 0;
        for (int j = i - c[i]; j <= i - 1; j++) {
            if (minn > temp[j]) {
                minn = temp[j];
                idx = j;
            }
        }
        v[i] = idx;
        if (a[idx] == 0) {
            a[idx] = 1;
        }
        temp[i] = minn + 1;
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << v[i] << ' ';
    // }
    // cout << '\n';
    // for (int i =  1; i <= n; i++) {
    //     cout << temp[i] << ' ';
    // }
    // cout << '\n';
    // cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
        if (a[i]) ans += temp[i] - temp[v[i]];
    }
    cout << ans;
    return 0;
}