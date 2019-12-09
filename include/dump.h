#pragma once

#include <bits/stdc++.h>

// debug
template<typename... Args>
std::string format(const std::string& fmt, Args... args) {
    auto sz = ::snprintf(nullptr, 0, fmt.c_str(), args...);
    std::string buf(sz, '?');
    ::snprintf(&buf[0], sz + 1, fmt.c_str(), args...);
    return buf;
}
#ifndef ONLINE_JUDGE
# define dbg(fmt, args...) (std::clog << "***DEBUG*** " << format(fmt, ##args) << std::endl)
# define VAR(e) (#e "=") << (e) << (",")
# define VAR2(e1,e2) VAR(e1) << VAR(e2)
# define VAR4(e1,e2,e3,e4) VAR2(e1,e2) << VAR2(e3,e4)
# define dump(e) (std::clog << "***DEBUG*** " << VAR(e) << std::endl)
# define dump2(e1,e2) (std::clog << "***DEBUG*** " << VAR2(e1,e2) << std::endl)
# define dump3(e1,e2,e3) (std::clog << "***DEBUG*** " << VAR2(e1,e2) << VAR(e3) << std::endl)
# define dump4(e1,e2,e3,e4) (std::clog << "***DEBUG*** " << VAR4(e1,e2,e3,e4) << std::endl)
# define dump5(e1,e2,e3,e4,e5) (std::clog << "***DEBUG*** " << VAR4(e1,e2,e3,e4) << VAR(e5) << std::endl)
# define dump6(e1,e2,e3,e4,e5,e6) (std::clog << "***DEBUG*** " << VAR4(e1,e2,e3,e4) << VAR2(e5,e6) << std::endl)
# define dump7(e1,e2,e3,e4,e5,e6,e7) (std::clog << "***DEBUG*** " << VAR4(e1,e2,e3,e4) << VAR2(e5,e6) << VAR(e7) << std::endl)
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
