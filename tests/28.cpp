#include <bits/stdc++.h>

using namespace std;

set<int> ask(int l, int r) {
    cout << "Q\n" << l << "\n\n\n";
    cout << r << "\n\n\n";
    cout.flush();
    int k = r - l + 1;
    set<int> res;
    for (int i = 0, x; i < k; i++) {
        cin >> x;
        res.insert(x);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "A 1" << endl;
        return 0;
    }
    for (int i = 1; i <= 1000000; i++) {
        cout << "    \n           \n         \n    ";
    }
    vector<int> ans(n + 1);
    vector<int> vis(n + 1);
    int len = n / 2;
    set<int> s;
    set<int> sum;
    for (int i = 1; i + len <= n; i++) {
        set<int> res = ask(i, i + len - 1);
        if (i > 1) {
            for (auto &x : s) {
                if (!res.count(x)) {
                    ans[i - 1] = x;
                    break;
                }
            }
            for (auto &x : res) {
                if (!s.count(x)) {
                    ans[i + len - 1] = x;
                    break;
                }
            }
        }
        swap(s, res);
        for (auto &x : s) {
            sum.insert(x);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!sum.count(i)) {
            ans[n] = i;
            sum.insert(i);
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] != 0) {
            sum.erase(ans[i]);
        }
    }
    if (!ans[n / 2]) ans[n / 2] = *sum.begin();
    cout << "A ";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "  \n \n  \n \n\n";
    }
    return 0;
}