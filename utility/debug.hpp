#if !defined(_DEBUG_HPP) && defined(LOCAL)

    #define _DEBUG_HPP

    template <typename A, typename B>
    inline string to_string(const pair<A, B>);

    template <typename A, typename B, typename C>
    inline string to_string(const tuple<A, B, C>);

    template <typename A, typename B, typename C, typename D>
    inline string to_string(const tuple<A, B, C, D>);

    inline string to_string(const string s) {
        return "'" + s + "'";
    }

    inline string to_string(const char *s) {
        return to_string((string) s);
    }

    inline string to_string(const bool b) {
        return (b ? "true" : "false");
    }

    inline string to_string(const char c) {
        return to_string(string(1, c));
    }

    inline string to_string(const vector<bool> v) {
        string res(1, '{');
        if (!v.empty()) {
            res += to_string(v.front());
        }
        for (int i = 1; i < static_cast<int>(v.size()); i++) {
            res += ", " + to_string(v[i]);
        }
        return res + '}';
    }

    template <const size_t N>
    inline string to_string(const bitset<N> v) {
        return v.to_string();
    }

    template <typename A>
    inline string to_string(const A v) {
        string res(1, '{');
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
    inline string to_string(const pair<A, B> p) {
        return '(' + to_string(p.first) + ", " + to_string(p.second) + ')';
    }

    template <typename A, typename B, typename C>
    inline string to_string(const tuple<A, B, C> p) {
        return '(' + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ')';
    }

    template <typename A, typename B, typename C, typename D>
    inline string to_string(const tuple<A, B, C, D> p) {
        return '(' + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ')';
    }

    inline void debug_out() {
        cerr << endl;
    }

    template <typename A, typename... B>
    void debug_out(const A a, const B... b) {
        cerr << ' ' << to_string(a);
        debug_out(b...);
    }

    #define debug(...) cerr << "Line " << __LINE__ << ", [" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)

#endif
