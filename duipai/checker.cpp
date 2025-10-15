#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

// 示例输出：
// 值不同
// wrong answer 18th numbers differ - expected: '4', found: '-1'

// 类型不同
// wrong output format Expected integer, but "a" found

// 长度不同
// wrong answer Answer contains longer sequence [length = 31], but output contains 25 elements

using namespace std;
vector<string> ans_lines, test_lines;
string line;

// 对比答案和输出
int contrast() {
    // 逐行比较内容
    int n = max(ans_lines.size(), test_lines.size());
    for (size_t i = 0; i < n; i++) {
        // 移除行尾空白字符
        if (i >= test_lines.size()) {
            cerr << "wrong answer Answer contains longer lines [length = " << ans_lines.size() << "], but output contains fewer elements\n";
            return 1; // 行数不同
        }
        if (i >= ans_lines.size()) {
            cerr << "wrong answer Output contains longer lines [length = " << test_lines.size() << "], but answer contains fewer elements\n";
            return 1; // 行数不同
        }
        ans_lines[i].erase(ans_lines[i].find_last_not_of(" \n\r\t") + 1);
        test_lines[i].erase(test_lines[i].find_last_not_of(" \n\r\t") + 1);

        if (ans_lines[i] != test_lines[i]) {
            cerr << "wrong answer ";
            cerr << i + 1 << "th lines differ - " << "";
            //expected: '4', found: '-1'
            cerr << "expected: " << ans_lines[i] << ", ";
            cerr << "found: " << test_lines[i] << "\n";
            return 1; // 内容不同
        }
    }
    return 0;
}

// 特殊判断
int special() {
    return 0;
}

int main() {
    ifstream ans_file("ans.txt");  // 正确程序输出
    ifstream test_file("test.txt"); // 待测程序输出

    if (!ans_file.is_open() || !test_file.is_open()) {
        cerr << "Error opening output files!" << endl;
        return 2; // 文件打开错误
    }

    // 读取正确程序输出
    while (getline(ans_file, line)) {
        ans_lines.push_back(line);
    }

    // 读取待测程序输出
    while (getline(test_file, line)) {
        test_lines.push_back(line);
    }

    ans_file.close();
    test_file.close();

    // 对比答案和输出
    return contrast();
    return 0; // 输出完全相同
}