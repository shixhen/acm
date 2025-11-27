#include <bits/stdc++.h>
using namespace std;

class AnimalShelf {
private:
    queue<int> dog_queue;   // dog队列
    queue<int> cat_queue;   // cat队列

public:
    AnimalShelf() {}

    void enqueue(int number, string type) {
        if (type[0] == 'd') {
            dog_queue.push(number);
        } else {
            cat_queue.push(number);
        }
    }
    
    void dequeueAny(int* number, string* type) {
        // 有队列为空的情况
        if (dog_queue.empty() && cat_queue.empty()) {
            number[0] = -1;
            type[0] = "none";
            return;
        } else if (dog_queue.empty()) {
            number[0] = cat_queue.front();
            cat_queue.pop();
            type[0] = "cat";
            return;
        } else if (cat_queue.empty()) {
            number[0] = dog_queue.front();
            dog_queue.pop();
            type[0] = "dog";
            return;
        }
        // 两个队列都不为空，比较队头元素
        if (dog_queue.front() < cat_queue.front()) {
            number[0] = dog_queue.front();
            dog_queue.pop();
            type[0] = "dog";
        } else {
            number[0] = cat_queue.front();
            cat_queue.pop();
            type[0] = "cat";
        }
    }

    int dequeueDog() {
        if (!dog_queue.empty()) {
            int num = dog_queue.front();
            dog_queue.pop();
            return num;
        } else {
            return -1;
        }
    }
    
    int dequeueCat() {
        if (!cat_queue.empty()) {
            int num = cat_queue.front();
            cat_queue.pop();
            return num;
        } else {
            return -1;
        }
    }
};

void solve() {
    int n;          // 操作次数
    cin >> n;
    int number;     // 编号
    string op;      // 操作类型
    string type;    // 动物种类
    AnimalShelf a;
    while (n--) {
        cin >> op;
        if (op == "enqueue") {
            cin >> number >> type;
            a.enqueue(number, type);
            continue;
        } else if (op == "dequeueAny") {
            a.dequeueAny(&number, &type);
        } else if (op == "dequeueDog") {
            number = a.dequeueDog();
            type = (number == -1 ? "none" : "dog");
        } else if (op == "dequeueCat") {
            number = a.dequeueCat();
            type = (number == -1 ? "none" : "cat");
        }
        cout << "[" << number << " " << type << "] ";
    }
    cout << "\n";
    return;
}

int main() {
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
}