#pragma once

#include <bits/stdc++.h>

namespace std {
    // basic.../string/char
    string to_string(const string& str) { return "\"" + str + "\""; }
    string to_string(char ch) { return "'" + string(1, ch) + "'"; }
    // pair/vector
    template <typename K, typename V>
    string to_string(const pair<K, V>& p) {
        return "<" + to_string(p.first) + "," + to_string(p.second) + ">";
    }
    template <typename T>
    string to_string(const vector<T>& vec) {
        string res = "{";
        for (auto& v : vec) res += to_string(v) + ",";
        if (res == "{") res += "}";
        else *--res.end() = '}';  // replace the last ',' with '}'
        return res;
    }
    // deque/list/set/multiset/unordered_set
    template <typename T>
    string to_string(const deque<T>& c) {
        vector<T> vec(c.begin(), c.end());
        return to_string(vec);
    }
    template <typename T>
    string to_string(const list<T>& c) {
        vector<T> vec(c.begin(), c.end());
        return to_string(vec);
    }
    template <typename T>
    string to_string(const set<T>& c) {
        vector<T> vec(c.begin(), c.end());
        return to_string(vec);
    }
    template <typename T>
    string to_string(const multiset<T>& c) {
        vector<T> vec(c.begin(), c.end());
        return to_string(vec);
    }
    template <typename T>
    string to_string(const unordered_set<T>& c) {
        vector<T> vec(c.begin(), c.end());
        return to_string(vec);
    }
    // map/multimap/unordered_map
    template <typename K, typename V>
    string to_string(const map<K, V>& c) {
        vector<pair<K, V>> vec(c.begin(), c.end());
        return to_string(vec);
    }
    template <typename K, typename V>
    string to_string(const multimap<K, V>& c) {
        vector<pair<K, V>> vec(c.begin(), c.end());
        return to_string(vec);
    }
    template <typename K, typename V>
    string to_string(const unordered_map<K, V>& c) {
        vector<pair<K, V>> vec(c.begin(), c.end());
        return to_string(vec);
    }
}

namespace fn {
    template <typename... Args>
    void ToVec(std::vector<std::string>& out, Args... args) {}
    template <typename T>
    void ToVec(std::vector<std::string>& out, T val) {
        out.push_back(std::to_string(val));
    }
    template <typename T, typename... Args>
    void ToVec(std::vector<std::string>& out, T val, Args... args) {
        out.push_back(std::to_string(val));
        ToVec(out, args...);
    }

    void Split(const std::string& str, const std::string& sep, std::vector<std::string>& vec) {
        std::string::size_type p = 0;
        while (p < str.size()) {
            auto p2 = str.find(sep, p);
            if (p2 == str.npos)
                p2 = str.size();
            vec.push_back(str.substr(p, p2-p));
            p = p2 + sep.size();
        }
    }

    std::string Merge(const std::string& s1, const std::vector<std::string>& v2) {
        std::vector<std::string> v1;
        Split(s1, ",", v1);
        // std::cerr << "s1: " << s1 << std::endl;
        // std::cerr << "v1: " << std::to_string(v1) << std::endl;
        // std::cerr << "v2: " << std::to_string(v2) << std::endl;
        std::string res;
        for (size_t i = 0, j = 0; i < v1.size() && j < v2.size(); ++i, ++j) {
            res += v1[i] + "=" + v2[j] + ";";
        }
        return res;
    }
}

// interface
#define DUMP(args...) \
    do { \
        const std::string s1 = #args; \
        std::vector<std::string> v2; \
        fn::ToVec(v2, ##args); \
        auto res = fn::Merge(s1, v2); \
        std::cerr << "***DUMP*** " << res << std::endl; \
     } while (0)

#define LINE(e) (std::cerr << "---LINE--- " << (e) << std::endl)
