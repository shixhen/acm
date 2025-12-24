#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e5 + 5;

long long tree[N];

int lowbit(int x) {
    return x & (-x);
}

void add(int x, long long val) {
    while (x < N) {
        tree[x] += val;
        x += lowbit(x);
    }
}

long long query(int x) {
    long long sum = 0;
    while (x > 0) {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]] = i;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        add(b[i], 1);
        long long l = query(b[i]);
        long long r = query(n) - query(b[i] - 1);
        ans += l * r;
    }
    cout << ans << "\n";
    return 0;
}