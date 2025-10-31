#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
    #include "testlib.h"
#else
    #include <testlib/testlib.h>
#endif

using namespace std;

void work() {
    int n = inf.readInt();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = inf.readInt();
    }
}

int main(int argc, char* argv[]) {
    setName("Interactor Tushen");
    registerInteraction(argc, argv);
    int t = inf.readInt();
    while (t--) {
        work();
    }
}