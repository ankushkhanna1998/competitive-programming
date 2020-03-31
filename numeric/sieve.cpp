inline vector<int> sieve(int n) {
    vector<bool> prime(n + 1, true);
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    vector<int> res;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            res.push_back(i);
        }
    }
    return res;
}
