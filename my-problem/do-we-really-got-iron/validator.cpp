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
    int sum = 0;
    inf.readEoln();
    for (int i = 0; i < t; i++) {
        int n = inf.readInt(1, 200000, "n");
        sum += n;
        inf.readEoln();
        for (int j = 0; j < n; j++) {
            inf.readInt(0, 2, "a[i]");
            if (j < n - 1) {
                inf.readSpace();
            }
        }
        inf.readEoln();
    }
    ensuref(sum <= 200000, "Sum of n over all testcases must not exceed 200000");
    inf.readEof();
}