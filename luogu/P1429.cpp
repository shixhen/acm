#include <bits/stdc++.h>

using namespace std;

constexpr int maxn = 4e5 + 1;

long long ans = LLONG_MAX;
int n; 
struct node{
	long long x, y;
	bool operator<(const node&t)const{
		return (x + 3333) * (y + 3333) > (t.x + 3333) * (t.y + 3333);
	}
} a[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].y;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= min(i + 233, n); j++){
			ans = min(ans, (a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
		}
	}
	for (int i = 1; i <= n; i++){
	    for (int j = n; j >= max(i + 1, n - 233); j--){
	        ans = min(ans, (a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
	    }
	}
	cout << ans;
	return 0;
}
