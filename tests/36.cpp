#include <iostream>
using namespace std;

int n;
char* s;

inline int imax(int a, int b) { return a > b ? a : b; }

int dfs(int idx) {
    if (idx > n) return 0;
    char val = s[idx - 1];
    if (val == '0') return 0;

    int hl = dfs(idx * 2);
    int hr = dfs(idx * 2 + 1);

    int bf = hl - hr;               
    cout << val << ' ' << bf << '\n'; 

    return 1 + imax(hl, hr);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        s = new char[n + 5];
        cin >> s;
        dfs(1);
        delete[] s;
        s = nullptr;
    }
    return 0;
}