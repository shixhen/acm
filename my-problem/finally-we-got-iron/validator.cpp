#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
    #include "testlib.h"
#else
    #include <testlib/testlib.h>
#endif

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, 1000, "t");
    int sum_n = 0;
    int sum_m = 0;
    inf.readEoln();
    for (int i = 0; i < t; i++) {
        int n = inf.readInt(1, 200000, "n");
        inf.readSpace();
        int m = inf.readInt(1, 200000, "m");
        sum_n += n;
        sum_m += m;
        inf.readEoln();
        for (int j = 0; j < n; j++) {
            int a = inf.readInt(0, 2, "a[i]");
            if (j < n - 1) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
        for (int j = 0; j < m; j++) {
            int h = inf.readInt(1, 2000000000, "h[i]");
            inf.readSpace();
            int p = inf.readInt(1, 2000000000, "p[i]");
            inf.readEoln();
        }
    }
    ensuref(sum_n <= 200000, "Sum of n over all testcases must not exceed 200000");
    ensuref(sum_m <= 200000, "Sum of m over all testcases must not exceed 200000");
    inf.readEof();
}