#include <bits/stdc++.h>

using namespace std;


int mid[10005];
int last[10005];
int ans;

void dfs(int ml, int mr, int ll, int lr) {
    if (ml > mr || ll > lr) return;
    if (ml == mr) {
        ans = min(ans, mid[ml]);
        return;
    }
    int root = last[lr];
    int idx = find(mid + ml, mid + mr + 1, root) - mid;
    dfs(ml, idx - 1, ll, ll + idx - ml - 1);
    dfs(idx + 1, mr, ll + idx - ml, lr - 1);
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        ans = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            cin >> mid[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> last[i];
        }
        dfs(1, n, 1, n);
        cout << ans << "\n";
    }  

    return 0;
}