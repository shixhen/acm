#include <bits/stdc++.h>

using namespace std;


bool check(int x) {



    return true;
}

int main() {
    int n;
    cin >> n;
    int l = 1, r = n;
    // 最小值二分
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return 0;
}
