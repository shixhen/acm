#include <bits/stdc++.h>

using namespace std;

int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int a[] = {0, 4, 8, 15, 16, 23, 42};
    int ans[7];
    int x = ask(1, 3);
    int y = ask(2, 3);
    int p, q, b, c;
    for (int i = 1; i <= 6; i++) {
        for (int j = i + 1; j <= 6; j++) {
            if (a[i] * a[j] == x) {
                b = i;
                c = j;
                break;
            }
        }
    }
    for (int i = 1; i <= 6; i++) {
        for (int j = i + 1; j <= 6; j++) {
            if (a[i] * a[j] == y) {
                p = i;
                q = j;
                break;
            }
        }
    }
    if (b == p) {
        ans[3] = a[b];
        ans[1] = a[c];
        ans[2] = a[q];
    } else if (b == q) {
        ans[3] = a[b];
        ans[1] = a[c];
        ans[2] = a[p];
    } else if (c == p) {
        ans[3] = a[c];
        ans[1] = a[b];
        ans[2] = a[q];
    } else {
        ans[3] = a[c];
        ans[1] = a[b];
        ans[2] = a[p];
    }
    x = ask(4, 6);
    y = ask(5, 6);
    for (int i = 1; i <= 6; i++) {
        for (int j = i + 1; j <= 6; j++) {
            if (a[i] * a[j] == x) {
                b = i;
                c = j;
                break;
            }
        }
    }
    for (int i = 1; i <= 6; i++) {
        for (int j = i + 1; j <= 6; j++) {
            if (a[i] * a[j] == y) {
                p = i;
                q = j;
                break;
            }
        }
    }
    if (b == p) {
        ans[6] = a[b];
        ans[4] = a[c];
        ans[5] = a[q];
    } else if (b == q) {
        ans[6] = a[b];
        ans[4] = a[c];
        ans[5] = a[p];
    } else if (c == p) {
        ans[6] = a[c];
        ans[4] = a[b];
        ans[5] = a[q];
    } else {
        ans[6] = a[c];
        ans[4] = a[b];
        ans[5] = a[p];
    }
    cout << "!";
    for (int i = 1; i <= 6; i++) {
        cout << ' ' << ans[i];
    }
}