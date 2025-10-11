#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y, z;    
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<long long> r(n + 1);
    vector<Node> a(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    auto check = [&](int k) {
        vector<long long> temp(n + 2);
        for (int i = 1; i <= k; i++) {
            temp[a[i].y] += a[i].x;
            temp[a[i].z + 1] -= a[i].x;
        }
        for (int i = 1; i <= n; i++) {
            temp[i] += temp[i - 1];
            if (temp[i] > r[i]) {
                return false;
            }
        }
        return true;
    };
    int l = 0, right = m;
    int mid;
    if (check(right)) {
        cout << 0 << '\n';
        return 0;
    }
    while (l < right) {
        mid = (l + right + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            right = mid - 1;
        }
    }
    cout << -1 << '\n';
    cout << right + 1 << endl;
    return 0;
}