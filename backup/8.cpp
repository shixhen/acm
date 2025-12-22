#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// 四进制数加法函数
string addQuaternary(string a, string b) {
    // 处理符号
    bool aPositive = (a[0] != '-');
    bool bPositive = (b[0] != '-');
    
    // 去掉符号位
    if (!aPositive) a = a.substr(1);
    if (!bPositive) b = b.substr(1);
    
    // 如果符号相同，执行绝对值加法
    if (aPositive == bPositive) {
        string result = "";
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        
        while (i >= 0 || j >= 0 || carry > 0) {
            int digitA = (i >= 0) ? (a[i] - '0') : 0;
            int digitB = (j >= 0) ? (b[j] - '0') : 0;
            
            int sum = digitA + digitB + carry;
            result = char('0' + sum % 4) + result;
            carry = sum / 4;
            
            i--;
            j--;
        }
        
        // 添加符号位
        if (!aPositive) result = "-" + result;
        return result;
    }
    // 如果符号不同，执行减法
    else {
        // 比较绝对值大小
        bool aLarger = false;
        if (a.length() > b.length()) {
            aLarger = true;
        } else if (a.length() < b.length()) {
            aLarger = false;
        } else {
            aLarger = (a >= b);
        }
        
        string larger = aLarger ? a : b;
        string smaller = aLarger ? b : a;
        bool resultPositive = aLarger ? aPositive : bPositive;
        
        string result = "";
        int borrow = 0;
        int i = larger.length() - 1;
        int j = smaller.length() - 1;
        
        while (i >= 0) {
            int digitLarger = larger[i] - '0';
            int digitSmaller = (j >= 0) ? (smaller[j] - '0') : 0;
            
            int diff = digitLarger - digitSmaller - borrow;
            if (diff < 0) {
                diff += 4;
                borrow = 1;
            } else {
                borrow = 0;
            }
            
            result = char('0' + diff) + result;
            i--;
            j--;
        }
        
        // 去掉前导零
        while (result.length() > 1 && result[0] == '0') {
            result = result.substr(1);
        }
        
        // 处理结果为0的情况
        if (result == "0") return "0";
        
        // 添加符号位
        if (!resultPositive) result = "-" + result;
        return result;
    }
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << addQuaternary(a, b) << endl;
    return 0;
}
