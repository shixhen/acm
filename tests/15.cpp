#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int j = 32 - __builtin_clz(10);
    cout << j << "\n";
    cout << (1 << (j - 1)) << "\n";
    return 0;
}