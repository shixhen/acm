#include <bits/stdc++.h>

using namespace std;

vector<long long> a[200005];
vector<array<long long, 2>> b;
long long f[200005];
void solve() {
    b.clear();  
    int n, m, _;
    long long temp = 0;
    cin >> n >> m;
    temp = n * m + 1;
    for (int i = 0; i <= temp + 1; i++) {
        f[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        a[i].clear();
        temp = 0;
        for (int j = 1; j <= m; j++) {
            cin >> _;
            temp += _;
            a[i].push_back(_);
        }
        b.push_back({temp, i});
    }
    sort(b.begin(), b.end());
    int p = 1;
    for (int i = b.size() - 1; i >= 0; i--) {
        temp = b[i][1];
        for (int j = 0; j < a[temp].size(); j++) {
            f[p++] = a[temp][j];
        }
    }
    for (int i = 1; i < p; i++) {
        f[i] += f[i - 1]; 
    }
    for (int i = 1; i < p; i++) {
        f[i] += f[i - 1]; 
    }
    cout << f[p - 1] << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}