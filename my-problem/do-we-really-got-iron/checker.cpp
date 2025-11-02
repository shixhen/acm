#ifdef ONLINE_JUDGE
    #include "testlib.h"
#else
    #include <testlib/testlib.h>
#endif
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int q = ouf.readInt();
    ouf.skipBlanks();
    ouf.readEof();
    quitf(_ok, "Ok with %d queries", q);
}