#include <iostream>
#include <string>

using namespace std;

struct BigInt{
    string value;
    BigInt operator*(const BigInt &that) {
        if (value == "0") {
            BigInt c;
            c.value = "0";
            return c;
        }
        if (that.value == "0") {
            BigInt c;
            c.value = "0";
            return c;
        }
        int len = value.size() + that.value.size();
        int temp[len] = {0};
        for (int i = value.size() - 1; i >= 0; i--) {
            for (int j  = that.value.size() - 1; j >= 0; j--) {
                temp[len - i - j - 2] += (value[i] - '0') * (that.value[j] - '0');
            }
        }
        for (int i = 0; i < len - 1; i++) {
            temp[i + 1] += temp[i] / 10;
            temp[i] %= 10;
        }
        while(!temp[len - 1]) {
            len--;
        }
        string result = "";
        BigInt c;
        for (int i = len - 1; i >= 0; i--) {
            result += temp[i] + '0';
        }
        c.value = result;
        return c;
    }

    BigInt operator+(const BigInt& other) {
        BigInt c;
        c.value = "";
        int a = value.size() - 1;
        int b = other.value.size() - 1;
        int temp = 0;
        int t = 0;
        while(a != -1 || b != -1) {
            if (a < 0) {
                a = 0;
                value[a] = '0';
            }
            if (b < 0) {
                b = 0;
                c.value = to_string((value[a] - '0' + t) % 10) + c.value;
            } else {
                c.value = to_string((value[a] - '0' + other.value[b] - '0' + t) % 10) + c.value;
            }
            t = (value[a] - '0' + other.value[b] - '0' + t) / 10;
            a--;
            b--;
        }
        if (t != 0) {
            c.value = to_string(t) + c.value;
            temp++;
        }
        return c;
    }
};

int main() {
    int n;
    cin >> n;
    BigInt a;
    BigInt sum;
    sum.value = "0";
    a.value = "1";
    for (int i = 1; i <= n; i++) {
        BigInt temp;
        temp.value = to_string(i);
        a = a * temp;
        sum = sum + a;
    }
    cout << sum.value << endl;
    return 0;
}

