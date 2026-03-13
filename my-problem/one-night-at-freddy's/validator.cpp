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
    int sum_n = 0;
    long long sum = 0;
    for (int i = 0; i < t; i++) {
        int n = inf.readInt(1, N, "n");
        inf.readSpace();
        long long m = inf.readInt(1, N, "m");
        inf.readSpace();
        long long l = inf.readInt(1, N, "l");
        inf.readEoln();
        ensuref(m * l <= N, "Sum of m * l over all test cases must not exceed %d, but got %lld", N, m * l);
        sum_n += n;
        sum += m * l;
        int a = inf.readInt(1, l, "a[i]");
        for (int j = 1; j < n; j++) {
            inf.readSpace();
            int a_t = a + 1;
            a = inf.readInt(a_t, l, "a[i]");
        }
        inf.readEoln();
    }
    ensuref(sum_n <= N, "Sum of n over all test cases must not exceed %d, but got %d", N, sum_n);
    ensuref(sum <= N, "Sum of m * l over all test cases must not exceed %d, but got %lld", N, sum);
    inf.readEof();
    return 0;
}