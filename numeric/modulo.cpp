const long MOD = static_cast<long>(1e9 + 7.0);

inline long add(long a, long b, const long M = MOD) {
    if ((a += b) >= M) {
        a -= M;
    }
    return a;
}

inline long sub(long a, long b, const long M = MOD) {
    if ((a -= b) < 0L) {
        a += M;
    }
    return a;
}

inline long mul(long a, long b, const long M = MOD) {
    return a * b % M;
}

inline long power(long a, long b, const long M = MOD) {
    assert(b >= 0L);
    long ans = 1L;
    while (b) {
        if (b & 1L) {
            ans = mul(ans, a);
        }
        a = mul(a, a);
        b >>= 1L;
    }
    return ans;
}

inline long inverse(long a, const long M = MOD) {
    a %= M;
    if (a < 0L) {
        a += M;
    }
    long b = M, u = 0L, v = 1L;
    while (a) {
        long t = b / a;
        b -= t * a;
        u -= t * v;
        swap(a, b);
        swap(u, v);
    }
    assert(b == 1L);
    if (u < 0L) {
        u += M;
    }
    return u;
}
