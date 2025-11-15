#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<int> a;
    int aa;
    while (cin >> aa) {
        a.push_back(aa);
    }
    vector<int> b(a.size() + 5, INT_MIN);
    vector<int> c(a.size() + 5, INT_MAX);
    function<int(int)> f = [&](int x) {
        int l = 0, r = a.size(), mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (b[mid] < x)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    };
    for (int i = 0; i < a.size(); i++) {
        b[f(a[i])] = a[i];
    }
    for (int i = 0; i < a.size(); i++) {
        c[lower_bound(c.begin(), c.end(), a[i]) - c.begin()] = a[i];
    }
    for (int i = 0; i < b.size(); i++) {
        if (b[i] == INT_MIN) {
            cout << i << "\n";
            break;
        }
    }
    for (int i = 0; i < c.size(); i++) {
        if (c[i] == INT_MAX) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}