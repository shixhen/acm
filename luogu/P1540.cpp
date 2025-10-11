#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int m, n;
    cin >> m >> n;
    unordered_map<int, bool> mp;
    queue<int> q;
    int ans = 0;
    int a;
    while (n--) {
        cin >> a;
        if (!mp[a]) {
            q.push(a);
            ans++;
            mp[a] = true;
            if (q.size() > m) {
                mp[q.front()] = false;
                q.pop();
            }
        }
    }
    cout << ans;
    return 0;
}