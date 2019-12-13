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

// 没有明显的退出点?完全模版和完全特化模版合一
template<typename... Args>
inline std::string stream_params(std::basic_ostream<char>& stream, Args... args) {
    stream << std::endl;  // 这个也是完全模板特化? 只要是args...这个参数不再被使用就认为是完全特化?
    return "";
}

template<typename T, typename... Args>
inline std::string stream_params(std::basic_ostream<char>& stream, T val, Args... args) {
    stream << val << " ";
    return stream_params(stream, args...);
}
