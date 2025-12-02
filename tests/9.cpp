#include<bits/stdc++.h>
using namespace std;
int query(int x, int y){
    cout << "? " << x << " "  << y << endl;
    int res;
    cin >> res;
    return res; 
}
int main(){
    int _;
    cin >> _;
    while(_--){
        int n;
        cin >> n;
        int x = 1, y = 0;
        vector<int> a(n + 2);
        while(x <= n){
            y = query(n + 1, x);
            if(y != n + 1) a[y] = 2; 
            x = y + 1;
        }
        x = 1, y = 0;
        while(a[x] == 2) x++;
        while(x <= n){
            while(a[x] == 2) x++;
            if(x > n) break;
            y = query(1, x);
            if(a[y] == 0) a[y] = 1;
            x = y + 1;
        }
        cout << "! ";
        for(int t = 1; t <= n; t++) cout << a[t] << " ";
        cout << endl;
    }
    return 0;
}