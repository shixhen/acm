#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int tree[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int v) {
    for (int i = x; i < N; i += lowbit(i)) tree[i] += v;
    return;
}

int query(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i)) res += tree[i];
    return res;
}
long long n, k;
vector<pair<long long, long long>> p;
bool check(long long x) {
    vector<long long> temp;
    //temp.reserve(p.size());
    for (auto &[a, b] : p) {
        temp.push_back(b - x * a);
    }
    sort(temp.begin(), temp.end());
    long long cnt = 0;
    for (int i = 0; i < p.size(); i++) {
        int pos = lower_bound(temp.begin(), temp.end(), p[i].second - x * p[i].first) - temp.begin() + 1;
        cnt += query(pos);
        add(pos, 1);
    }
    for (int i = 0; i < p.size(); i++) {
        int pos = lower_bound(temp.begin(), temp.end(), p[i].second - x * p[i].first) - temp.begin() + 1;
        add(pos, -1);
    }
    return cnt >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    p.resize(n);
    for (auto &[x, y] : p) cin >> x >> y;
    sort(p.begin(), p.end(), [](const pair<long long, long long> &a, const pair<long long, long long> &b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });
    long long l = -1000000000LL, r = 1000000000LL;
    while (l < r) {
        long long mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << '\n';
    return 0;
}