#include <bits/stdc++.h>

using namespace std;

int main() {
    int v;
    int n;
    int a;
    cin >> v >> n;
    vector<int> f(v + 1);
    f[v] = true;
    while (n--) {
        cin >> a;
        for (int i = a; i <= v; i++) {
            f[i - a] |= f[i];
        }
    }
    for (int i = 0; i <= v; i++) {
        if (f[i]) {
            cout << i;
            break;
        }
    }
    return 0; 
}