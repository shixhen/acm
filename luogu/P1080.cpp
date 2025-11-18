#include <bits/stdc++.h>

using namespace std;

struct P{
    int a;
    int b;
};
P p[1003];

bool cmp(P x, P y) {
    return x.a * x.b < y.a * y.b;
}

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
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        scanf("%d %d", &p[i].a, &p[i].b);
    }
    sort(p + 1, p + n + 1, cmp);
    BigInt temp;
    temp = BigInt(p[0].a);
    BigInt ans;
    for (int i = 1; i <= n; i++) {
        if (ans < (temp / p[i].b)) {
            ans = (temp / p[i].b);
        }
        temp = temp * BigInt(p[i].a);
    }
    cout << ans << "\n";
    return 0;
}