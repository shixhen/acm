#include <bits/stdc++.h>

using namespace std;

int a[500005];
bool ans[500005] = {false};
unordered_map<int, unordered_map<int, bool>> mp;

void solve() {
    mp.clear();
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++) { 
        ans[i] = false;
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        cin >> u;
        cin >> v;
        if (a[u] == a[v]) {
            ans[a[u]] = true;
            continue;
        }
        if (mp[u][a[v]]) ans[a[v]] = true;
        else mp[u][a[v]] = true;
        if (mp[v][a[u]]) ans[a[u]] = true;
        else mp[v][a[u]] = true;
        
    }
    for (int i = 1; i <= n; i++) {
        cout << (char) (ans[i] + '0');
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}