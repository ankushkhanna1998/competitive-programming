#if !defined(_DEBUG_HPP) && defined(LOCAL)

    #define _DEBUG_HPP

    inline string to_string(const char c) {
        return string(1, c);
    }

    template <typename A, typename B>
    inline string to_string(pair<A, B>);

    template <typename A, typename B, typename C>
    inline string to_string(tuple<A, B, C>);

    template <typename A, typename B, typename C, typename D>
    inline string to_string(tuple<A, B, C, D>);

    inline string to_string(const string &s) {
        return "'" + s + "'";
    }

    inline string to_string(const char *s) {
        return to_string((string) s);
    }

    inline string to_string(bool b) {
        return (b ? "true" : "false");
    }

    inline string to_string(vector<bool> v) {
        string res("{");
        if (v.size()) {
            res += to_string(v.front());
        }
        for (int i = 1; i < static_cast<int>(v.size()); i++) {
            res += ", " + to_string(v[i]);
        }
        return res + '}';
    }

    template <size_t N>
    inline string to_string(bitset<N> v) {
        return v.to_string();
    }

    template <typename A>
    inline string to_string(A v) {
        string res("{");
        bool first = true;
        for (const auto &x : v) {
            if (!first) {
                res += ", ";
            }
            first = false;
            res += to_string(x);
        }
        return res + '}';
    }

    template <typename A, typename B>
    inline string to_string(pair<A, B> p) {
        return '(' + to_string(p.first) + ", " + to_string(p.second) + ')';
    }

    template <typename A, typename B, typename C>
    inline string to_string(tuple<A, B, C> p) {
        return '(' + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ')';
    }

    template <typename A, typename B, typename C, typename D>
    inline string to_string(tuple<A, B, C, D> p) {
        return '(' + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ')';
    }

    inline void debug_out() {
        cerr << endl;
    }

    template <typename A, typename... B>
    void debug_out(A a, B... b) {
        cerr << ' ' << to_string(a);
        debug_out(b...);
    }

    #define debug(...) cerr << "Line " << __LINE__ << ", [" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)

#endif
