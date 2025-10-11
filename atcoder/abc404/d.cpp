#include <bits/stdc++.h>

using namespace std;

vector<int> z[15];
vector<long long> c;
int num = 0;
long long cnt[105];
long long ans = 0x3f3f3f3f3f3f3f3f;
int n, m;
void dfs(int d, long long cost) {
    for (int k = 0; k <= 2; k++) {
        if (k) cost += c[d];
        for (auto &i: z[d]) {
            if (cnt[i] < 2 and cnt[i] + k >= 2) num++; 
            cnt[i] += k;
            
        }
        if (d == n and num == m) {
            ans = min(ans, cost); 
        }
        if (d < n)
            dfs(d + 1, cost);
        for (auto &i: z[d]) {
            if (cnt[i] >= 2 and cnt[i] - k < 2) num--; 
            cnt[i] -= k;
            
        }
        
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> n >> m;
    c.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    int k;
    int a;
    for (int i = 1; i <= m; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> a;
            z[a].push_back(i);
        }
    }
    dfs(1, 0ll);
    cout << ans;
    return 0;
}