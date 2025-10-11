#include <bits/stdc++.h>


using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        for (auto &i: a) {
            cin >> i;
            sum ^= i;
        }
        

    return 0;
}