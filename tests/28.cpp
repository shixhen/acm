#include <bits/stdc++.h>

using namespace std;
int howManyBits(int x) {
  /********* Begin *********/
    int sign = x >> 31;
    x = (sign & ~x) | (~sign & x);
    int bit16, bit8, bit4, bit2, bit1, bit0;
    bit16 = !!(x >> 16) << 4;
    x = x >> bit16;
    bit8 = !!(x >> 8) << 3;
    x = x >> bit8;
    bit4 = !!(x >> 4) << 2;
    x = x >> bit4;
    bit2 = !!(x >> 2) << 1;
    x = x >> bit2;
    bit1 = !!(x >> 1);
    x = x >> bit1;
    bit0 = x;
    return bit16 + bit8 + bit4 + bit2 + bit1 + bit0 + 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int x = -1;
    cout << howManyBits(x);
    return 0;
}