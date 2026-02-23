#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
    #include "testlib.h"
#else
    #include <testlib/testlib.h>
#endif

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int t = inf.readInt(1, 10000, "t");
    int sum = 0;
    inf.readEoln();
    for (int i = 0; i < t; i++) {
        int n = inf.readInt(1, 200000, "n");
        inf.readSpace();
        int m = inf.readInt(n, 1000000000, "m");
        sum += n;
        inf.readEoln();
    }
    ensuref(sum <= 200000, "Sum of n over all testcases must not exceed 200000");
    inf.readEof();
}