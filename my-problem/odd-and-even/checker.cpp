#ifdef ONLINE_JUDGE
    #include "testlib.h"
#else
    #include <testlib/testlib.h>
#endif
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int t = inf.readInt();
    int n;
    string s;
    for (int i = 1; i <= t; i++) {
        n = inf.readInt();
        s = ouf.readLine();
        vector<int> a;
        stringstream ss(s);
        int x;
        while (ss >> x) {
            a.push_back(x);
        }
        if ((int)a.size() != n) {
            quitf(_wa, "Expected %d numbers in the permutation, but got %d! [testcase %d]", n, (int)a.size(), i);
        }
        vector<int> b = a;
        sort(a.begin(), a.end());
        for (int j = 0; j < n; j++) {
            if (a[j] != j + 1) {
                quitf(_wa, "Expected a permutation of numbers from 1 to %d, but not found %d! [testcase %d]", n, j + 1, i);
            }
        }
        for (int j = 1; j < n - 1; j++) {
            if (((b[j - 1] + b[j]) & 1) == ((b[j] + b[j + 1]) & 1)) {
                quitf(_wa, "Wrong permutation at position %d, (%d + %d) % 2 = (%d + %d) % 2! [testcase %d]", j, b[j - 1], b[j], b[j], b[j + 1], i);
            }
        }
    }
    ouf.skipBlanks();
    ouf.readEof();
    quitf(_ok, "All test cases passed. (%d test case(s))", t);
}