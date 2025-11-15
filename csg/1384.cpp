#include <bits/stdc++.h>
using namespace std;

// 判断字符是否为操作符
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// 获取操作符优先级
int getPrecedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// 中缀表达式转后缀表达式（逆波兰表示法）
string infixToPostfix(string infix) {
    stack<char> operators;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        // 如果是操作数（字母或数字），直接添加到结果
        if (isalnum(c)) {
            while (i < infix.length() && isalnum(infix[i])) {
                postfix += infix[i];
                i++;
            }
            postfix += ' '; // 添加空格分隔符
            i--; // 回退一个字符位置
        }
        // 如果是左括号，压入栈
        else if (c == '(') {
            operators.push(c);
        }
        // 如果是右括号，弹出栈中元素直到遇到左括号
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                postfix += ' '; // 添加空格分隔符
                operators.pop();
            }
            if (!operators.empty()) {
                operators.pop(); // 弹出左括号
            }
        }        // 如果是操作符
        else if (isOperator(c)) {
            while (!operators.empty() && operators.top() != '(' &&
                   getPrecedence(operators.top()) >= getPrecedence(c)) {
                postfix += operators.top();
                postfix += ' '; // 添加空格分隔符
                operators.pop();
            }
            operators.push(c);
        }
    }
    
    // 弹出栈中剩余的操作符
    while (!operators.empty()) {
        postfix += operators.top();
        postfix += ' '; // 添加空格分隔符
        operators.pop();
    }
    
    return postfix;
}

// 中缀表达式转前缀表达式（波兰表示法）
string infixToPrefix(string infix) {
    // 反转中缀表达式
    reverse(infix.begin(), infix.end());
    
    // 交换括号
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    
    // 修改优先级规则，对于相同优先级的操作符，从右到左处理
    stack<char> operators;
    string result = "";
    
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        // 如果是操作数（字母或数字），直接添加到结果
        if (isalnum(c)) {
            while (i < infix.length() && isalnum(infix[i])) {
                result += infix[i];
                i++;
            }
            result += ' '; // 添加空格分隔符
            i--; // 回退一个字符位置
        }
        // 如果是左括号，压入栈
        else if (c == '(') {
            operators.push(c);
        }
        // 如果是右括号，弹出栈中元素直到遇到左括号
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                result += operators.top();
                result += ' '; // 添加空格分隔符
                operators.pop();
            }
            if (!operators.empty()) {
                operators.pop(); // 弹出左括号
            }
        }        // 如果是操作符
        else if (isOperator(c)) {
            while (!operators.empty() && operators.top() != '(' &&
                   getPrecedence(operators.top()) > getPrecedence(c)) {
                result += operators.top();
                result += ' '; // 添加空格分隔符
                operators.pop();
            }
            operators.push(c);
        }
    }
    
    // 弹出栈中剩余的操作符
    while (!operators.empty()) {
        result += operators.top();
        result += ' '; // 添加空格分隔符
        operators.pop();
    }
    
    // 反转结果得到前缀表达式
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string infix;
        cin >> infix;
        string postfix = infixToPostfix(infix);
        string prefix = infixToPrefix(infix);
        cout << prefix.substr(1) << "\n";
        cout <<  postfix << "\n\n";
    }
    
    return 0;
}
