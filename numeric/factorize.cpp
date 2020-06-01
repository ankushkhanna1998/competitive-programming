template <typename T>
inline vector<T> factorize(T n) {
    vector<T> res(__builtin_ctzll(n), 2);
    n >>= (int) res.size();
    for (T i = 3; i * i <= n; i += 2) {
        while (!(n % i)) {
            n /= i;
            res.push_back(i);
        }
    }
    if (n > 2) {
        res.push_back(n);
    }
    return res;
}

class factorizer {
public:

    const int MAXN;

    vector<int> spf;

    inline factorizer(int _n) : MAXN(_n), spf(_n + 1) {
        iota(spf.begin(), spf.end(), 0);
        for (int i = 4; i <= MAXN; i += 2) {
            spf[i] = 2;
        }
        for (int i = 3; i * i <= MAXN; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= MAXN; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    inline vector<int> factorize(int n) const {
        assert(n > 0 && n <= MAXN);
        vector<int> res;
        while (n > 1) {
            res.push_back(spf[n]);
            n /= spf[n];
        }
        return res;
    }

};
