#include <bits/stdc++.h>

using namespace std;

class Account {
private:
    int balance;
    double interestRate;
    int num;
    char type;
public:
    Account() : balance(0), interestRate(0), num(0), type(' ') { }
    Account(double balance, double interestRate, int num, char type) : balance(balance), interestRate(interestRate), num(num), type(type) {

    }
    Account(const Account &a) {
        balance = a.balance;
        interestRate = 0.015;
        num = a.num + 50000000;
        type = a.type;
    }

    void calc_interest() {
        balance += balance * interestRate;
        cout << "Account=" << num << "--sum=" << balance << endl;
    }

    void show() {
        cout << "Account=" << num << "--" << (type == 'P' ? "Person" : "Enterprise") << "--sum=" << balance << "--rate=" << interestRate << endl;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int num;
        char type;
        int balance;
        cin >> num >> type >> balance;
        Account a1(balance, 0.005, num, type);
        Account a2(a1);
        cin >> type;
        if (type == 'C') {
            a1.calc_interest();
        } else if (type == 'P') {
            a1.show();
        }
        cin >> type;
        if (type == 'C') {
            a2.calc_interest();
        } else if (type == 'P') {
            a2.show();
        }
    }
    return 0;
}