#include <bits/stdc++.h>

using namespace std;

inline void read(int &x) {
    x = 0;
    int f = 0;
    char ch = 0;
    while(!isdigit(ch)) {
        f |= (ch == '-');
        ch = getchar();
    }
    while(isdigit(ch)) {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    x = f ? -x : x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    return 0;
}


