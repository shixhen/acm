#include <bits/stdc++.h>

using namespace std;


struct BigInt {
    vector<int> val;
    BigInt() {val.push_back(0);}
    BigInt(int x) {
        while (x) {
            val.push_back(x % 10);
            x /= 10;
        }
    }

    BigInt operator+(const BigInt& other) const {
        BigInt result;
        int carry = 0;
        for (size_t i = 0; i < max(val.size(), other.val.size()) || carry; i++) {
            if (i < val.size()) carry += val[i];
            if (i < other.val.size()) carry += other.val[i];
            result.val.push_back(carry % 10);
            carry /= 10;
        }
        return result;
    }

    BigInt operator*(const BigInt& other) const {
        BigInt result;
        result.val.resize(val.size() + other.val.size());
        for (size_t i = 0; i < val.size(); i++) {
            for (size_t j = 0; j < other.val.size(); j++) {
                result.val[i + j] += val[i] * other.val[j];
                if (result.val[i + j] >= 10) {
                    result.val[i + j + 1] += result.val[i + j] / 10;
                    result.val[i + j] %= 10;
                }
            }
        }
        while (result.val.size() > 1 && result.val.back() == 0) {
            result.val.pop_back();
        }
        // 取后600百位
        result.val.resize(min(result.val.size(), size_t(600)));
        return result;
    }

    BigInt operator/(int divisor) const {
        BigInt result;
        result.val.resize(val.size());
        int remainder = 0;
        for (int i = val.size() - 1; i >= 0; i--) {
            remainder = remainder * 10 + val[i];
            result.val[i] = remainder / divisor;
            remainder %= divisor;
        }
        while (result.val.size() > 1 && result.val.back() == 0) {
            result.val.pop_back();
        }
        return result;
    }

    friend bool operator<(const BigInt& a, const BigInt& b) {
        if (a.val.size() != b.val.size()) return a.val.size() < b.val.size();
        for (int i = a.val.size() - 1; i >= 0; i--) {
            if (a.val[i] != b.val[i]) return a.val[i] < b.val[i];
        }
        return false;
    }

    friend ostream& operator<<(ostream& os, const BigInt& num) {
        for (auto it = num.val.rbegin(); it != num.val.rend(); ++it) {
            os << *it;
        }
        return os;
    }
};



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int p;
    cin >> p;
    cout << (int) (log10(2) * p + 1) << "\n";
    BigInt res(1);
    BigInt a(2);
    while (p) {
        if (p & 1) res = res * a;
        a = a * a;
        p >>= 1;
    }
    int k = 500 - res.val.size();
    int cnt = 0;
    int idx = min(res.val.size() - 1,(size_t) 499);
    for (int i = 1; i <= 500; i++) {
        if (k > 0) {
            cout << 0;
            k--;
        } else {
            if (idx == 0) {
                cout << res.val[0] - 1;
            } else {
                cout << res.val[idx--];
            }
        }
        cnt++;
        if (cnt == 50) {
            cout << "\n";
            cnt = 0;
        }
    }
    return 0;
}
