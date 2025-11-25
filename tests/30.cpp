#include <bits/stdc++.h>
using namespace std;

class AnimalShelf {
private:
	int *dog_number;
	int *cat_number;
	int dog_size;
	int cat_size;
	int dogl;
	int catl;
public:
	AnimalShelf() {
		dog_size = 0;
		cat_size = 0;
		dogl = 0;
		catl = 0;
		dog_number = new int[1005];
		cat_number = new int[1005];
	}
	void enqueue(int number, string type) {
		if (type[0] == 'd') {
			dog_number[dog_size++] = number;
		} else {
			cat_number[cat_size++] = number;
		}
	}
	
	void dequeueAny(int* number, string* type) {
		if (dogl < dog_size && (catl >= cat_size || dog_number[dogl] < cat_number[catl])) {
			number[0] = dog_number[dogl++];
			type[0] = "dog";
		} else if (catl < cat_size) {
			number[0] = cat_number[catl++];
			type[0] = "cat";
		} else {
			number[0] = -1;
			type[0] = "none";
		}
	}
	int dequeueDog() {
		if (dogl < dog_size) {
			return dog_number[dogl++];
		} else {
			return -1;
		}
	}
	
	int dequeueCat() {
		if (catl < cat_size) {
			return cat_number[catl++];
		} else {
			return -1;
		}
	}
};

void solve() {
	int n;
	cin >> n;
	AnimalShelf a;
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		if (s == "enqueue") {
			int x;
			string na;
			cin >> x >> na;
			a.enqueue(x, na); 
		} else if (s == "dequeueAny") {
			int *number = new int[1];
			string *type = new string[1];
			a.dequeueAny(number, type);
			cout << "[" << number[0] << " " << type[0] << "] ";
		} else if (s == "dequeueDog") {
			int x = a.dequeueDog();
			if (x != -1) {
				cout << "[" << x << " dog" << "] ";
			} else {
				cout << "[-1 none] ";
			}
		} else if (s == "dequeueCat") {
			int x = a.dequeueCat();
			if (x != -1) {
				cout << "[" << x << " cat" << "] ";
			} else {
				cout << "[-1 none] ";
			}
		}
	}
	cout << "\n"; 
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	} 
	return 0;
} 
