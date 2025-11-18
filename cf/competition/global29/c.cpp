#include <bits/stdc++.h>

using namespace std;
   
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == '1') {
        s = '1' + s;
        n++;
    }
    if (s.back() == '1') {
        s = s + '1';
        n++;
    }
    vector<int> a(n + 2, 0);
    s = ' ' + s + ' ';
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0' && i == 0) {
            continue;
        }
        if (s[i] == '1') {
            int j = i;
            while (j <= n && s[j] == '1') {
                j++;
            }
            if (j > i + 1) {
                if (a[i - 1] == 1) {
                    cout << "No\n";
                    return;
                }
                a[i - 1] = 2;
                if (j >= n) break;
                if (a[j] == 2) {
                    cout << "No\n";
                    return;
                }
                a[j] = 1;
                
                i = j;
            } else {
                if (j > n && a[i - 1] == 1) {
                    cout << "No\n";
                    return;
                }
                if (a[i - 1] == 1) {
                    a[j] = 2;
                } else if (a[i - 1] == 2) {
                    a[j] = 1;
                }
                i = j;
            }
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--) { solve();}
    return 0;
}