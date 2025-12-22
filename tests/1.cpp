#include <bits/stdc++.h>

using namespace std;


const int N = 1000000 + 5;

int a[N];
int b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    a[1] = 1;
    a[2] = 2;
    b[2] = 2;
    for (int i = 3; i <= n; i++) {
        a[i] = a[i - 1] + a[i - 2] + b[i - 1];
        
        b[i] = b[i - 1] + a[i - 2] * 2;

        a[i] %= 10000;
        b[i] %= 10000;
    }
    cout << a[n] << "\n";
    return 0;
}