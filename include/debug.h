#pragma once

#include <bits/stdc++.h>

// debug
template<typename C>
std::string ToStr(const C& c) {
    std::string ret("{");
    for (auto v : c)
        ret += std::to_string(v) + ",";
    ret += "}";
    return ret;
}
template<typename T1, typename T2>
std::string ToStr(const std::map<T1, T2>& c) {
    std::string ret("{");
    for (auto& kv : c)
        ret += "<" + std::to_string(kv.first) + "," + std::to_string(kv.second) + ">,";
    ret += "}";
    return ret;
}
template<typename... Args>
std::string format(const std::string& fmt, Args... args) {
    auto sz = ::snprintf(nullptr, 0, fmt.c_str(), args...);  // effective char size
    std::string buf(sz, '?');
    ::snprintf(&buf[0], sz + 1, fmt.c_str(), args...);  // len include '\0'
    return buf;
}
#ifndef ONLINE_JUDGE
# define PRE() (std::clog << "***DEBUG*** ")
# define POST() std::endl
# define dbg(fmt, args...) (PRE() << format(fmt, ##args) << POST())
# define VAR(e) (#e "=") << (e) << (",")
# define VAR2(e1,e2) VAR(e1) << VAR(e2)
# define VAR4(e1,e2,e3,e4) VAR2(e1,e2) << VAR2(e3,e4)
# define dump(e) (PRE() << VAR(e) << POST())
# define dump2(e1,e2) (PRE() << VAR2(e1,e2) << POST())
# define dump3(e1,e2,e3) (PRE() << VAR2(e1,e2) << VAR(e3) << POST())
# define dump4(e1,e2,e3,e4) (PRE() << VAR4(e1,e2,e3,e4) << POST())
# define dump5(e1,e2,e3,e4,e5) (PRE() << VAR4(e1,e2,e3,e4) << VAR(e5) << POST())
# define dump6(e1,e2,e3,e4,e5,e6) (PRE() << VAR4(e1,e2,e3,e4) << VAR2(e5,e6) << POST())
# define dump7(e1,e2,e3,e4,e5,e6,e7) (PRE() << VAR4(e1,e2,e3,e4) << VAR2(e5,e6) << VAR(e7) << POST())
#else
# define dbg(fmt, args...)
# define dump(e)
# define dump2(e1,e2)
# define dump3(e1,e2,e3)
# define dump4(e1,e2,e3,e4)
# define dump5(e1,e2,e3,e4,e5)
# define dump6(e1,e2,e3,e4,e5,e6)
# define dump7(e1,e2,e3,e4,e5,e6,e7)
#endif
