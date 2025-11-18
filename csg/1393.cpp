#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

string s;
void solve() {
    int n;
    n = (int) s.size();
    map<char, int> mp;
    map<int, char> mp2;
    for (auto& i : s) {
        mp[i]++;
    }
    int tot = 0;
    priority_queue < pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> > > q;
    for (auto it : mp) {
        q.push({ it.second, ++tot });
        mp2[tot] = it.first;
    }
    n = tot;
    vector<int> fa(3 * n + 1);
    vector<int> h(3 * n + 1);
    vector<int> ls(3 * n + 1);
    vector<int> rs(3 * n + 1);
    int root;
    while (q.size() > 1) {
        auto node1 = q.top();
        int x = node1.second;
        q.pop();
        auto node2 = q.top();
        q.pop();
        int y = node2.second;
        q.push({ node1.first + node2.first, ++tot });
        fa[x] = tot;
        fa[y] = tot;
        ls[tot] = x;
        rs[tot] = y;
        h[y] = 1;
        root = tot;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        int cnt = 0;
        while (j != root) {
            cnt++;
            j = fa[j];
        }
        //cout << mp2[i] << " " << cnt << "\n";
        ans += mp[mp2[i]] * cnt;
    }
    cout << ans << "\n";
    return;
}

int main() {
    int t;
    while (cin >> s) {
        solve();
    }
}

