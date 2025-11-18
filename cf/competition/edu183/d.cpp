#include <bits/stdc++.h>

using namespace std;

vector<int> cnt(1000, 0x3f3f3f3f);
vector<int> pre(1000, -1);

void init() {
    cnt[0] = 0;
    for (int i = 2; i <= 30; i++) {
        cnt[i * (i - 1) / 2] = i;
        pre[i * (i - 1) / 2] = i;
    }
    for (int i = 1; i <= 900; i++) {
        for (int j = 2; j <= 30; j++) {
            if (i + j * (j - 1) / 2 <= 900) {
                if (cnt[i + j * (j - 1) / 2] > cnt[i] + j) {
                    cnt[i + j * (j - 1) / 2] = cnt[i] + j;
                    pre[i + j * (j - 1) / 2] = j;
                }
            }
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    int x = n * (n - 1) / 2 - k;
    //cout << x << "\n";
    //cout << cnt[x] << "\n";
    if (cnt[x] > n) {
        cout << 0 << "\n";
        return;
    }
    vector<int> v;
    while (x > 0) {
        v.push_back(pre[x]);
        x -= pre[x] * (pre[x] - 1) / 2;
    }
    
    // for (auto &it : v) {
    //     cout << it << " ";
    // }
    // cout << "\n";
    int p1 = 1;
    int p2 = v.size() + 1;
    vector<int> ans;
    for (auto &it : v) {
        ans.push_back(p1++);
        for (int i = 1; i < it; i++) {
            ans.push_back(p2++);
        }
    }
    for (int i = n; i >= p2; i--) {
        cout << i << " ";
    }
    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << "\n";
    return;
}

int main() {
    init();
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}