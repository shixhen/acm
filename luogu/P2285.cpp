#include <bits/stdc++.h>

using namespace std;

struct node {
    int time, x, y;
};

int get_dis(node a, node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<node> a(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i].time >> a[i].x >> a[i].y;
    }
    vector<int> f(m + 1);
    for (int i = 1; i <= m; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (get_dis(a[i], a[j]) <= a[i].time - a[j].time) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    cout << *max_element(f.begin(), f.end()) << "\n";
    return 0;
}