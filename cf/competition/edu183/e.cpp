#include <bits/stdc++.h>

using namespace std;

void solve(int n, int k) {
    cin >> n >> k;
    int x = n * (n - 1) / 2 - k;
    int num = 0;
    vector<int> v;
    for (int i = 30; i >= 2; i--) {
        while (x >= i * (i - 1) / 2) {
            v.push_back(i);
            x -= i * (i - 1) / 2;
            num += i;
        }
    }
    num--;
    //cout << num << "----\n";
    // for (auto &it : v) {
    //     cout << it << " ";
    // }
    //cout << "\n";
    if (num >= n) {
        cout << 0 << "\n";
        return;
    }
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
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) {
        int n, k;
        for (int i = 2; i <= 10; i++) {
            for (int j = 0; j <= (i * (i - 1) / 2); j++) {
                cout << i << " " << j << ":\n";
                solve(i, j);
                cout << "\n";
            }
        }
    }
    return 0;
}