#include <bits/stdc++.h>

using namespace std;

constexpr int N = (1 << 21);

int d[N];
int a[25];
int n;
int tar;
void dfs(int u, vector<array<int, 3>> ops) {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(d, 0x3f, sizeof(d));
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n != 0) {
        cout << "-1\n";
        return 0;
    }
    return 0;
}