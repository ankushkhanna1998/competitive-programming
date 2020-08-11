const int64_t MOD = static_cast<int64_t>(1e9 + 7);

inline int64_t add(int64_t a, const int64_t b, const int64_t M = MOD) {
    if ((a += b) >= M) {
        a -= M;
    }
    return a;
}

inline int64_t sub(int64_t a, const int64_t b, const int64_t M = MOD) {
    if ((a -= b) < 0) {
        a += M;
    }
    return a;
}

inline int64_t mul(const int64_t a, const int64_t b, const int64_t M = MOD) {
    return a * b % M;
}

inline int64_t power(int64_t a, int64_t b, const int64_t M = MOD) {
    assert(b >= 0);
    int64_t ans = 1;
    while (b) {
        if (b & 1) {
            ans = mul(ans, a, M);
        }
        a = mul(a, a, M);
        b >>= 1;
    }
    return ans;
}

inline int64_t inverse(int64_t a, const int64_t M = MOD) {
    int64_t b = M, u = 0, v = 1;
    while (a) {
        int64_t t = b / a;
        b -= t * a; swap(a, b);
        u -= t * v; swap(u, v);
    }
    assert(b == 1);
    return sub(u, 0, M);
}
