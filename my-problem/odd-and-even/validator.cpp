#ifdef ONLINE_JUDGE
    #include "testlib.h"
#else
    #include <testlib/testlib.h>
#endif
#include <bits/stdc++.h>

using namespace std;
constexpr int N = 200000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10000, "t");
    inf.readEoln();
    int sum = 0;
    for (int i = 0; i < t; i++) {
        int n = inf.readInt(1, N, "n");
        inf.readEoln();
        sum += n;
    }
    ensuref(sum <= N, "Sum of n over all test cases must not exceed %d, but got %d", N, sum);
    inf.readEof();
    return 0;
}