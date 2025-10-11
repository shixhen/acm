#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int ans = 0;
    char ch;
    ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    while(isdigit(ch)) {
        ans = (ans << 3) + (ans << 1) + (ch ^ 48);
        ch = getchar();
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t = read();
    cout << t;
    return 0;
}