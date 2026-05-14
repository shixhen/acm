#include <bits/stdc++.h>

using namespace std;

int a[15] = {0};
vector<int> v;
vector<vector<int>> ans;
int n, r;

void dfs(int idx, int d) {
    if (d == r + 1 && (int) v.size() == r) {
        ans.push_back(v);
        return;
    }
    for (int i = idx; i >= 1; i--) {
        v.push_back(a[i]);
        dfs(i - 1, d + 1);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> r) {
        ans.clear();
        v.clear();
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        dfs(n, 1);
        reverse(ans.begin(), ans.end());
        for (auto &v : ans) {
            reverse(v.begin(), v.end());
            for (int i = 0; i < r; i++) {
                cout << v[i] << " \n"[i == r - 1];
            }
        }
    }

    return 0;
}