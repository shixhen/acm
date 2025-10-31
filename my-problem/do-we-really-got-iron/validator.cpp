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
    inf.readEoln();
    for (int i = 0; i < t; i++) {
        int n = inf.readInt(1, 200000, "n");
        for (int j = 0; j < n; j++) {
            int a = inf.readInt(0, 2, "a[i]");
            if (j < n - 1) {
                inf.readSpace();
            }
        }
        inf.readEoln();
        int q = inf.readInt(1, n, "q");
        inf.readEoln();
        for (int j = 0; j < q; j++) {
            int p = inf.readInt(1, n, "p");
            if (j < q - 1) {
                inf.readSpace();
            }
        }
        inf.readEoln();
        for (int j = 0; j < q; j++) {
            int h = inf.readInt(0, 1, "h");
            if (j < q - 1) {
                inf.readSpace();
            }
        }
        inf.readEoln();
    }
    inf.readEof();
}