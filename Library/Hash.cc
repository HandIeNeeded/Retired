const int X1 = 4243;
const int MOD1 = 1e9 + 7;
const int X2 = 10007;
const int MOD2 = 42424243;
const int LEN = 3e5 + 5;

struct Hash {
    int a, b;

    Hash() {}
    Hash(int a) : a(a), b(a) {}
    Hash(int a, int b) : a(a), b(b) {}
};

bool operator < (const Hash& a, const Hash& b) {
    if (a.a != b.a) {
        return a.a < b.a;
    }
    return a.b < b.b;
}

bool operator == (const Hash& a, const Hash& b) {
    return a.a == b.a && a.b == b.b;
}

Hash operator * (const Hash& a, const Hash& b) {
    return Hash((1LL * a.a * b.a) % MOD1, (1LL * a.b * b.b) % MOD2);
}

Hash operator + (const Hash& a, const Hash& b) {
    Hash c(a.a + b.a, a.b + b.b);
    if (c.a >= MOD1) {
        c.a -= MOD1;
    }
    if (c.b >= MOD2) {
        c.b -= MOD2;
    }
    return c;
}

const Hash X(X1, X2);

inline void init() {
    pw[0] = Hash(1);
    for (int i = 1; i < LEN; ++i) {
        pw[i] = pw[i - 1] * X;
    }
}
