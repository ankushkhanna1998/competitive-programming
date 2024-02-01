const int64_t MOD = static_cast<int64_t>(1e9 + 7);

inline int64_t inverse(int64_t a, const int64_t M = MOD) {
  int64_t b = M, u = 0, v = 1;
  while (a != 0) {
    const int64_t t = b / a;
    b -= t * a;
    u -= t * v;
    swap(a, b);
    swap(u, v);
  }
  assert(b == 1);
  return (u < 0 ? (u + M) : u);
}

template <const int64_t M = MOD>
class modular {

private:

  static_assert(M > 0, "MOD cannot be non-positive");

  int64_t value;

public:

  inline modular() : value(0) {}

  template <typename T>
  inline modular(const T &x) : value(normalize(x)) {}

  template <typename T>
  static inline int64_t normalize(const T &x) {
    const int64_t result = static_cast<int64_t>((-M <= x && x < M) ? x : (x % M));
    return (result < 0 ? (result + M) : result);
  }

  static inline int64_t get_mod() {
    return M;
  }

  template <typename T> inline explicit operator T() const { return static_cast<T>(value); }
  inline const int64_t& operator()() const { return value; }
  inline modular& operator+=(const modular &x) { if ((value += x.value) >= M) value -= M; return *this; }
  inline modular& operator-=(const modular &x) { if ((value -= x.value) < 0) value += M; return *this; }
  inline modular& operator*=(const modular &x) { value = normalize(value * x.value); return *this; }
  inline modular& operator/=(const modular &x) { return (*this *= modular(inverse(x.value, M))); }
  inline modular& operator++() { return (*this += 1); }
  inline modular& operator--() { return (*this -= 1); }
  inline modular operator++(const int) { modular result(*this); *this += 1; return result; }
  inline modular operator--(const int) { modular result(*this); *this -= 1; return result; }
  inline modular operator-() const { return modular(-value); }
  inline modular operator+(const modular &x) const { return (modular(value) += x); }
  inline modular operator-(const modular &x) const { return (modular(value) -= x); }
  inline modular operator*(const modular &x) const { return (modular(value) *= x); }
  inline modular operator/(const modular &x) const { return (modular(value) /= x); }
  inline bool operator==(const modular &x) const { return value == x.value; }
  inline bool operator<(const modular &x) const { return value < x.value; }
  inline bool operator>(const modular &x) const { return value > x.value; }
  inline bool operator<=(const modular &x) const { return value <= x.value; }
  inline bool operator>=(const modular &x) const { return value >= x.value; }
  inline bool operator!=(const modular &x) const { return value != x.value; }

  template <const int64_t M_, typename T>
  friend inline T& operator>>(T&, modular<M_>&);
};

template <const int64_t M = MOD, typename T> inline modular<M> operator+(const T &lhs, const modular<M> &rhs) { return (modular<M>(lhs) += rhs); }
template <const int64_t M = MOD, typename T> inline modular<M> operator-(const T &lhs, const modular<M> &rhs) { return (modular<M>(lhs) -= rhs); }
template <const int64_t M = MOD, typename T> inline modular<M> operator*(const T &lhs, const modular<M> &rhs) { return (modular<M>(lhs) *= rhs); }
template <const int64_t M = MOD, typename T> inline modular<M> operator/(const T &lhs, const modular<M> &rhs) { return (modular<M>(lhs) /= rhs); }
template <const int64_t M = MOD, typename T> inline bool operator==(const T &lhs, const modular<M> &rhs) { return (modular<M>(lhs) == rhs); }
template <const int64_t M = MOD, typename T> inline bool operator<(const T &lhs, const modular<M> &rhs) { return (modular<M>(lhs) < rhs); }
template <const int64_t M = MOD, typename T> inline bool operator>(const T &lhs, const modular<M> &rhs) { return (modular<M>(lhs) > rhs); }
template <const int64_t M = MOD, typename T> inline bool operator<=(const T &lhs, const modular<M> &rhs) { return (modular<M>(lhs) <= rhs); }
template <const int64_t M = MOD, typename T> inline bool operator>=(const T &lhs, const modular<M> &rhs) { return (modular<M>(lhs) >= rhs); }
template <const int64_t M = MOD, typename T> inline bool operator!=(const T &lhs, const modular<M> &rhs) { return (modular<M>(lhs) != rhs); }

template <const int64_t M = MOD, typename A, typename B>
inline modular<M> power(const A &_a, const B &_b) {
  modular<M> a = _a;
  int64_t b = static_cast<int64_t>(_b);
  assert(b >= 0);
  modular<M> result = 1;
  while (b != 0) {
    if ((b & 1) == 1) {
      result *= a;
    }
    a *= a;
    b >>= 1;
  }
  return result;
}

template <const int64_t M = MOD>
inline modular<M> inverse(const modular<M> &a) {
  return modular<M>(inverse(a(), M));
}

template <const int64_t M = MOD>
inline string to_string(const modular<M> &number) {
  return to_string(number());
}

template <const int64_t M = MOD>
inline const int64_t& abs(const modular<M> &number) {
  return number();
}

template <const int64_t M = MOD, typename T>
inline T& operator>>(T &input_stream, modular<M> &number) {
  int64_t x;
  input_stream >> x;
  number.value = modular<M>::normalize(x);
  return input_stream;
}

template <const int64_t M = MOD, typename T>
inline T& operator<<(T &output_stream, const modular<M> &number) {
  return (output_stream << number());
}

template <const int64_t M = MOD>
class combinatorics {

private:

  static vector<modular<M>> _fact, _inv_fact;

  inline void ensure(const int n) const {
    assert(n >= 0);
    while ((int) _fact.size() < n + 1) {
      _fact.push_back(_fact.back() * (int) _fact.size());
      _inv_fact.push_back(1 / _fact.back());
    }
  }

public:

  inline modular<M> fact(const int n) const {
    ensure(n);
    return _fact[n];
  }

  inline modular<M> inv_fact(const int n) const {
    ensure(n);
    return _inv_fact[n];
  }

  inline modular<M> permute(const int n, const int k) const {
    if (k < 0 || k > n) {
      return 0;
    }
    ensure(n);
    return _fact[n] * _inv_fact[n - k];
  }

  inline modular<M> choice(const int n, const int k) const {
    if (k < 0 || k > n) {
      return 0;
    }
    ensure(n);
    return _fact[n] * _inv_fact[n - k] * _inv_fact[k];
  }
};
template <const int64_t M> vector<modular<M>> combinatorics<M>::_fact(1, 1);
template <const int64_t M> vector<modular<M>> combinatorics<M>::_inv_fact(1, 1);

using mint = modular<MOD>;
using math = combinatorics<MOD>;
