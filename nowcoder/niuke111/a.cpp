#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> a(3);
    for (int &i: a) cin >> i;
    vector<int> b(3);
    for (int &i: b) cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int cnt = 0;
    int j = 0;
    for (int i = 0; i < 3; i++) {
        if (b[i] > a[j]) {
            cnt++;
            j++;
        }
    }
    if (cnt >= 2) cout << "Yes"; 
    else cout << "No";
}