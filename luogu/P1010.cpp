#include <bits/stdc++.h>

using namespace std;


void work(int t) {
    vector<int> temp;
    int i = 0;
    while (t) {
        if (t & 1) {
            temp.push_back(i);
        }
        i++;
        t >>= 1;
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        if (temp[i] >= 2) {
            cout << "2(";
            work(temp[i]);
            cout << ")";
        } else if (temp[i] == 0){
            cout << "2(0)";
        } else if (temp[i] == 1) {
            cout << "2";
        }
        if (i != 0) {
            cout << "+";
        }
    }
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    work(n);
    return 0;
}