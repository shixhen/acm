#include <bits/stdc++.h>

using namespace std;

bool is_o(int x) {
    if (x % 3) return false;
    x /= 3;
    return (x & (x - 1)) == 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, x, y;
    cin >> n >> m;
    vector<bool> st((1 << n));
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        q.push({x, y});
    }
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == n) {
            st[y] = true;
            cout << y << endl;
            continue;
        }
        q.push({x + 1, (y << 1) - 1});
        q.push({x + 1, y << 1});
    }
    vector<string> ans;
    ans.push_back(" ");
    string s((3 << (n - 1)) + 1, ' ');
    
    return 0;
}    

//1                       o
//2                      / \
//3                     /   \
//4                    /     \
//5                   /       \
//6                  /         \
//7                 /           \
//8                /             \
//9               /               \
//10             /                 \
//11            /                   \
//12           /                     \
//13          o                       o
//14         / \                     / \
//15        /   \                   /   \
//         /     \                 /     \        
//        /       \               /       \       
//       /         \             /         \      
//      o           o           o           o     
//     / \         / \         / \         / \    
//    /   \       /   \       /   \       /   \   
//   o     o     o     o     o     o     o     o  
//  / \   / \   / \   / \   / \   / \   / \   / \ 
// o   o o   o o   o o   o o   o o   o o   o o   o