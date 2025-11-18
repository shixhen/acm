#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(3 * n + 1);
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        q.push({ a[i], i });
    }
    vector<int> fa(3 * n + 1);
    vector<int> h(3 * n + 1);
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
        h[y] = 1;
        root = tot;
    }
    for (int i = 1; i <= n; i++) {
        string s = "";
        int j = i;
        while (j != root) {
            s += h[j] + '0';
            j = fa[j];
        }
        cout << a[i] << "-";
        reverse(s.begin(), s.end());
        cout << s << "\n";
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

