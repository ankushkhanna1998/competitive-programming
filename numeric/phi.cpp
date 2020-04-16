inline long phi(long n) {
    long ans = n;
    n >>= __builtin_ctzll(n);
    if (ans != n) {
        ans >>= 1L;
    }
    for (long i = 3L; i * i <= n; i += 2L) {
        if (!(n % i)) {
            ans -= ans / i;
            while (!(n % i)) {
                n /= i;
            }
        }
    }
    if (n > 2L) {
        ans -= ans / n;
    }
    return ans;
}

inline vector<int> phi_all(int n) {
    vector<int> phi(n + 1);
    iota(phi.begin(), phi.end(), 0);
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    return phi;
}
