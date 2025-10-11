#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int k, d, m, f;
    cin >> k >> d >> m >> f;
    priority_queue<int> kk;
    priority_queue<int> dd;
    priority_queue<int> mm;
    priority_queue<int> ff;
    int _;
    for (int i = 1; i <= k; i++) {
        cin >> _;
        kk.push(_);
    }
    for (int i = 1; i <= d; i++) {
        cin >> _;
        dd.push(_);
    }
    for (int i = 1; i <= m; i++) {
        cin >> _;
        mm.push(_);
    }
    for (int i = 1; i <= f; i++) {
        cin >> _;
        ff.push(_);
    }
    int n;
    cin >> n;
    int a, b, c;
    cout << fixed << setprecision(2);
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        int sum = 0;
        int num = a + b + c + 1;
        sum += kk.top();
        kk.pop();
        while (a--) {
            sum += dd.top();
            dd.pop();
        }
        while (b--) {
            sum += mm.top();
            mm.pop();
        }
        while (c--) {
            sum += ff.top();
            ff.pop();
        }
        cout << (double) sum / num << '\n';
    }
    return 0;
}