inline long phi(long n) {
    long ans = n;
    for (long i = 2L; i * i <= n; i++) {
        if (!(n % i)) {
            ans -= ans / i;
            while (!(n % i)) {
                n /= i;
            }
        }
    }
    if (n > 1L) {
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
}
