#include <bits/stdc++.h>

using namespace std;

const int INF = 2147483647;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int op, x;
    
    set<int> numbers;
    
    numbers.insert(-INF);
    numbers.insert(INF);
    
    for (int i = 0; i < n; i++) {
        cin >> op >> x;
          if (op == 1) {
            //cout << "1 ";
            int rank = distance(numbers.begin(), numbers.lower_bound(x));
            cout << rank << "\n";
        } else if (op == 2) {
            //cout << "2 ";
            auto it = next(numbers.begin(), x);
            cout << *it << "\n";
        }
        else if (op == 3) {
            //cout << "3 ";
            auto it = numbers.lower_bound(x);
            --it;
            if (*it == -INF) {
                cout << -INF << "\n";
            } else {
                cout << *it << "\n";
            }
        } 
        else if (op == 4) {
            //cout << "4 ";
            auto it = numbers.upper_bound(x);
            if (*it == INF) {
                cout << INF << "\n";
            } else {
                cout << *it << "\n";
            }
        } 
        else if (op == 5) {
            numbers.insert(x);
        }
    }

    return 0;
}