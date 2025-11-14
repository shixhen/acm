#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(3 * n + 1);
    vector<char> ch(3 * n + 1);
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        q.push({ a[i], i });
    }
    for (int i = 1; i <= n; i++) {
        cin >> ch[i];
    }
    vector<int> fa(3 * n + 1);
    vector<int> h(3 * n + 1);
    vector<int> ls(3 * n + 1);
    vector<int> rs(3 * n + 1);
    int tot = n;
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
    int qq;
    cin >> qq;
    string s;
    while (qq--) {
        string ans = "";
        cin >> s;
        int j = root;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                j = rs[j];
            }
            else {
                j = ls[j];
            }
            if (j == 0) {
                ans = "error";
                break;
            }
            if (ch[j]) {
                ans += ch[j];
                j = root;
            }
            else if (i == s.size() - 1) {
                ans = "error";
            }
        }
        cout << ans << "\n";
    }
    
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
