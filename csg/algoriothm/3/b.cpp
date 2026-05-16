#include <bits/stdc++.h>

using namespace std;

struct BigBinary
{
    std::vector<int> x;     // 由低位到高位保存二进制位
    bool neg;               // 标记数的正负
    void Init(){x.clear(); neg = false;}
    BigBinary(){Init();}
    void Print()
    {
        if(neg && !x.empty()) printf("-");
        for(int i = x.size() - 1; i >= 0; i --)
            printf("%d", x[i]);
        if(x.empty()) printf("0");
        printf("\n");
    }
};

static void Normalize(BigBinary &v)
{
    while (!v.x.empty() && v.x.back() == 0) v.x.pop_back();
    if (v.x.empty()) v.neg = false;
}

static int CompareAbs(const BigBinary &a, const BigBinary &b)
{
    if (a.x.size() != b.x.size()) return a.x.size() < b.x.size() ? -1 : 1;
    for (int i = (int)a.x.size() - 1; i >= 0; --i) {
        if (a.x[i] != b.x[i]) return a.x[i] < b.x[i] ? -1 : 1;
    }
    return 0;
}

static BigBinary AddAbs(const BigBinary &a, const BigBinary &b)
{
    BigBinary result;
    size_t n = max(a.x.size(), b.x.size());
    result.x.assign(n + 1, 0);

    int carry = 0;
    for (size_t i = 0; i < n; ++i) {
        int sum = carry;
        if (i < a.x.size()) sum += a.x[i];
        if (i < b.x.size()) sum += b.x[i];
        result.x[i] = sum & 1;
        carry = sum >> 1;
    }
    result.x[n] = carry;

    Normalize(result);
    return result;
}

static BigBinary SubAbs(const BigBinary &larger, const BigBinary &smaller)
{
    BigBinary result;
    result.x.assign(larger.x.size(), 0);

    int borrow = 0;
    for (size_t i = 0; i < larger.x.size(); ++i) {
        int diff = larger.x[i] - borrow;
        if (i < smaller.x.size()) diff -= smaller.x[i];
        if (diff < 0) {
            diff += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.x[i] = diff;
    }

    Normalize(result);
    return result;
}

BigBinary Add(BigBinary &a, BigBinary &b)
{
    BigBinary result;

    if (a.neg == b.neg) {
        result = AddAbs(a, b);
        result.neg = a.neg;
        Normalize(result);
        return result;
    }

    int cmp = CompareAbs(a, b);
    if (cmp == 0) return result;

    if (cmp > 0) {
        result = SubAbs(a, b);
        result.neg = a.neg;
    } else {
        result = SubAbs(b, a);
        result.neg = b.neg;
    }
    Normalize(result);
    return result;
}

BigBinary Minus(BigBinary &a, BigBinary &b)
{
    BigBinary result;

    if (a.neg != b.neg) {
        result = AddAbs(a, b);
        result.neg = a.neg;
        Normalize(result);
        return result;
    }

    int cmp = CompareAbs(a, b);
    if (cmp == 0) return result;

    if (!a.neg) {
        if (cmp > 0) {
            result = SubAbs(a, b);
            result.neg = false;
        } else {
            result = SubAbs(b, a);
            result.neg = true;
        }
    } else {
        // (-|a|) - (-|b|) = |b| - |a|
        if (cmp > 0) {
            result = SubAbs(a, b);
            result.neg = true;
        } else {
            result = SubAbs(b, a);
            result.neg = false;
        }
    }

    Normalize(result);
    return result;
}
BigBinary Mul(BigBinary &a, BigBinary &b)
{
    BigBinary result;
    if (a.x.empty() || b.x.empty()) return result;

    result.x.assign(a.x.size() + b.x.size(), 0);

    for (size_t i = 0; i < a.x.size(); ++i) {
        if (a.x[i] == 0) continue;

        for (size_t j = 0; j < b.x.size(); ++j) {
            result.x[i + j] += a.x[i] * b.x[j];
        }
    }
    // 处理进位
    int carry = 0;
    for (size_t i = 0; i < result.x.size(); ++i) {
        int sum = result.x[i] + carry;
        result.x[i] = sum & 1;
        carry = sum >> 1;
    }
    result.neg = (a.neg != b.neg);
    Normalize(result);
    return result;
}

static BigBinary SliceBits(const BigBinary &v, int l, int r)
{
    BigBinary part;
    int n = (int)v.x.size();
    if (l >= n || l >= r) return part;
    r = min(r, n);
    part.x.assign(v.x.begin() + l, v.x.begin() + r);
    Normalize(part);
    return part;
}

static BigBinary FasterMulRec(BigBinary a, BigBinary b)
{
    Normalize(a);
    Normalize(b);
    BigBinary zero;
    if (a.x.empty() || b.x.empty()) return zero;

    bool neg = (a.neg != b.neg);
    a.neg = false;
    b.neg = false;

    const int BASE_CASE = 256;
    if ((int)min(a.x.size(), b.x.size()) <= BASE_CASE) {
        BigBinary base = Mul(a, b);
        if (!base.x.empty()) base.neg = neg;
        return base;
    }

    int n = (int)max(a.x.size(), b.x.size());
    int m = n >> 1;

    BigBinary A = SliceBits(a, m, (int)a.x.size());
    BigBinary B = SliceBits(a, 0, m);
    BigBinary C = SliceBits(b, m, (int)b.x.size());
    BigBinary D = SliceBits(b, 0, m);

    BigBinary AC = FasterMulRec(A, C);
    BigBinary BD = FasterMulRec(B, D);

    BigBinary A_minus_B = Minus(A, B);
    BigBinary D_minus_C = Minus(D, C);
    BigBinary P = FasterMulRec(A_minus_B, D_minus_C);

    BigBinary cross = Add(P, AC);
    cross = Add(cross, BD);

    BigBinary AC_shift = AC;
    if (!AC_shift.x.empty()) AC_shift.x.insert(AC_shift.x.begin(), 2 * m, 0);
    BigBinary cross_shift = cross;
    if (!cross_shift.x.empty()) cross_shift.x.insert(cross_shift.x.begin(), m, 0);

    BigBinary result = Add(AC_shift, cross_shift);
    result = Add(result, BD);
    Normalize(result);
    if (!result.x.empty()) result.neg = neg;
    return result;
}

void MulN2(BigBinary &a, int n_2)
{
    if (a.x.empty() || n_2 <= 0) return;
    a.x.insert(a.x.begin(), n_2, 0);
}
BigBinary FasterMul(BigBinary &a, BigBinary &b)
{
    return FasterMulRec(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    while (cin >> a >> b) {
        BigBinary A, B;
        A.neg = (a[0] == '-');
        B.neg = (b[0] == '-');
        for (int i = a.size() - 1; i >= A.neg; --i) {
            A.x.push_back(a[i] - '0');
        }
        for (int i = b.size() - 1; i >= B.neg; --i) {
            B.x.push_back(b[i] - '0');
        }
        BigBinary result = FasterMulRec(A, B);
        result.Print();
    }
}