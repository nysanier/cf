#pragma once

#include <bits/stdc++.h>

// template
template<typename... Args>
inline bool co(Args... args) {
    return true;
}

// full special
template<typename T>
inline bool co(const T& val) {
    std::cout << val << std::endl;
    return true;
}

// part special
template<typename T, typename... Args>
inline bool co(T val, Args... args) {
    std::cout << val << " ";
    return co(args...);
}
