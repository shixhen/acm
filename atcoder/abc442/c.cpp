#include <bits/stdc++.h>

using namespace std;

vector<int> g[200005];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        long long t = n - 1 - g[i].size();
        if (t < 3) {
            cout << 0 << " ";
        } else {
            cout <<(long long) t * (t - 1) * (t - 2) / 6ll << " ";
        }
    }
    return 0;
}