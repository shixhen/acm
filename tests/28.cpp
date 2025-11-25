#include <bits/stdc++.h>
using std::string;
constexpr int N = 1005;

int data[N];

int front = 0, rear = 0;

class AnimalShelf {
public:
	void enqueue(int number, string type);
	
	void dequeueAny(int* number, string* type);

	int dequeueDog;
	
	int dequeueCat;
};


int main() {
    // 入队操作
    auto push = [&](int x) { data[rear++] = x; };
    // 取队头元素
    auto get_front = [&]() { return (front < rear ? data[front] : -1); };
    // 出队操作
    auto pop = [&]() { if (front < rear) front++; };
    // 判空操作
    auto empty = [&]() { return front == rear; };
    
    return 0;
}
