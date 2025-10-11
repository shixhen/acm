#include <bits/stdc++.h>

using namespace std;

int ff[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int d, g;
    cin >> d >> g;
    vector<array<int, 3>> a(g);
    int sum = 10;
    for (auto &[t, f, h]: a) {
        cin >> t >> f >> h;
        sum += f;
    }
    sort(a.begin(), a.end());
    ff[0] = 10;
    int last = 0;
    int ans = 10;
    for (int i = 0; i < g; i++) {
        auto [t, f, h] = a[i];
        for (int j = d; j >= 0; j--) {
            if (ff[j] >= t) {
                if (j + h >= d) {
                    cout << t << "\n";
                    return 0;
                }
                ff[j + h] = max(ff[j + h], ff[j]);
                ff[j] += f;
            }
        }
    }
    cout << ff[0] << "\n";
    return 0;
}