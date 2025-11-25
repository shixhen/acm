#include <bits/stdc++.h>

using namespace std;

int lowbit(int x) {
    return x & (-x);
}

vector<int> tree;
int n;

void add(int x) {
    while (x <= n) {
        tree[x]++;
        x += lowbit(x);
    }
    return;
}

int query(int x) {
    int res = 0;
    while (x) {
        res += tree[x];
        x -= lowbit(x);
    }
    return res;
}

void solve() {
    cin >> n;
    tree.assign(n + 1, 0);
    vector<int> a(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        add(a[i]);
        //cout << i << " " << query(n - i) << "\n";
        if (i - query(n - i) == i) {
            //cout << i << " " << n - i + 1 << endl;
            cout << "No\n";
            return;
        }
    }
    vector<int> b(n + 1);
    cout << "Yes\n";
    if (a[1] < a[n]) {
        for (int i = 2; i < n; i++) {
            if (a[i] > a[1]) {
                cout << a[1] << " " << a[i] << "\n";
                
            } else {
                cout << a[i] << " " << a[n] << "\n";
                
            }
        }
        cout << a[1] << " " << a[n] << "\n";
    } else {
        int j = n;
        while (j >= 1 && a[j] < a[1]) {
            j--;
        }
        int k = 1;
        while (k <= n && a[k] > a[n]) {
            k++;
        }
        b[1] = 1;
        b[n] = 2;
        for (int i = 2; i < n; i++) {
            if (a[i] > a[1]) {
                cout << a[1] << " " << a[i] << "\n";
                b[i] = 1;
            } else if (a[i] < a[n]) {
                cout << a[i] << " " << a[n] << "\n";
                b[i] = 2;
            } else {
                if (i < j) {
                    cout << a[i] << " " << a[j] << "\n";
                    b[i] = 2;
                } else {
                    cout << a[i] << " " << a[k] << "\n";
                    b[i] = 1;
                }
            }
        }
        j = 1;
        while (b[j] == 1) {
            j++;
        }
        
        k = n;
        while (b[k] == 2) {
            k--;
        }
        cout << a[j] << " " << a[k] << "\n";
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}