#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

int aa[] = {1, 2, 4, 8};

int bb[] = {12, 3};

int cc[] = {5, 10};
int dd[] = {15};

int change(int x, int y) {
    int res = 0;
    for (int i = 0; i <= 15; i++) {
        if (x & (1 << i)) {
            if ((i ^ y) < 15) {
                res |= (1 << ((i ^ y)));
            }
        }
    }
    return res;
}

vector<vector<pair<int, int>>> edge((1 << 16) + 5, vector<pair<int, int>>());
vector<int> dis((1 << 16) + 5, 0x3f3f3f3f);

void solve() {
    int n;
    cin >> n;
    int st = 0;
    string x, y;
    for (int i = 1, now; i <= n; i++) {
        cin >> x >> y;
        x += y;
        now = 0;
        for (int i = 0; i < 4; i++) {
            now = now * 2 + (x[i] - '0');
        }
        st |= (1 << now);
    }
    cout << dis[st] << "\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    cin >> a >> b >> c >> d;
    b = min(b, 2 * a);
    c = min(c, 2 * a);
    d = min({d, 2 * c, 2 * b, 4 * a});
    for (int i = 0; i < (1 << 16); i++) {
        for (int j = 0; j < 4; j++) {
            edge[change(i, aa[j])].push_back({a, i});
        }
        for (int j = 0; j < 2; j++) {
            edge[change(i, bb[j])].push_back({b, i});
            edge[change(i, cc[j])].push_back({c, i});
        }
        edge[change(i, dd[0])].push_back({d, i});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dis[0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        auto [dist, u] = q.top();
        q.pop();
        if (dis[u] < dist) continue;
        for (auto [w, v] : edge[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    while (t--) {
        solve();
    }
    return 0;
}