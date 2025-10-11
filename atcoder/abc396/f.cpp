#include <bits/stdc++.h>
#define tt 205
using namespace std;

int a[tt], temp[tt], b[tt];
long long change[tt];
bool st[tt];
long long fans[tt];
long long ans = 0;
void merge_sort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else {
            for (int x = i; x < j;x++) {
                change[a[i]]--;
            }
            change[a[j]] += mid + 1 - i;
            temp[k++] = a[j++];
            ans += mid + 1 - i;
        }
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (int i = l; i <= r; i++) a[i] = temp[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    merge_sort(1, n);
    fans[0] = ans;
    
    for (int i = 1; i <= n; i++) {
        if (st[b[i]]) continue;
        st[b[i]] = true;
        //fans[m - b[i]] -= (n - change[b[i]] - 1);
        fans[m - b[i]] +=  change[b[i]];
    }
    cout << fans[0] << '\n';
    for (int i = 1; i < m; i++) {
        fans[i] += fans[i - 1];
        cout << fans[i] << '\n';
    }
    return 0;
}