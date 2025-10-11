#include <bits/stdc++.h>

using namespace std;



void last(string pre, string inor) {
    if (pre.empty()) return;
    char root = pre[0];
    int k = inor.find(root);
    string lpre = pre.substr(1, k);
    string rpre = pre.substr(k + 1);
    string linor = inor.substr(0, k);
    string rinor = inor.substr(k + 1);
    last(lpre, linor);
    last(rpre, rinor);
    cout << root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string pre, inor;
    cin >> inor >> pre;
    last(pre, inor);
    return 0;
}