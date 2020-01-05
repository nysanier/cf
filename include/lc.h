#pragma once

#include <bits/stdc++.h>
#include "dump.h"

// 还可以有更好的方法来解析数据, 根据'['/']'/'"'出现的个数位置即可知道当前那个vec需要数据
// 在出现之前，先移除多余的空格，即不在""中的空格，方便处理
// 总体方法: 状态机
// 在处理的是否，如果引号或者括号不配对，那么直接assert
namespace lc{
using namespace std;

void Parse(std::vector<std::string>& out, const std::string& si) {
    out.clear();
    std::istringstream strin(si);
    std::string key, op, val;
    while (strin >> key >> op >> val) {
        if (op != "=") {
            DUMP("invalid op", op);
            assert(0);
            break;
        }
        if (val[val.size()-1] == ',') val.resize(val.size()-1);
        out.push_back(val);
    }
}
void Read(std::vector<std::string>& in, std::string& out) {
    std::string si, so;
    const std::string li("输入：");
    const std::string lo("输出：");
    for (;;) {
        std::getline(std::cin, si);
        if (si.size() < li.size()) continue;
        if (si.find(li) == 0) break;
    }
    for (;;) {
        std::getline(std::cin, so);
        if (so.size() < lo.size()) continue;
        if (so.find(lo) == 0) break;
    }
    // DUMP(si);
    // DUMP(so);
    Parse(in, si.substr(li.size()));  // remove 输入：
    out = so.substr(lo.size());  // remove 输出：
}

string rq(const std::string& s) { return s.substr(1,s.size()-2); }
string rb(const std::string& s) { return rq(s); }
template <typename T>
void ParseArg(const std::string& in, T& val) {
    DUMP("unsupport");
    assert(0);
}
void ParseArg(const std::string& in, int& val) {
    val = std::stoi(in);
    // DUMP("int", in, val);
}
void ParseArg(const std::string& in, string& val) {
    val = rq(in);  // remove quota "abc"
    // DUMP("str", in, val);
}
void ParseArg(const std::string& in, vector<int>& val) {
    vector<string> out;
    fn::Split(out, rb(in), ",");  // remove bracket [1,2] -> 1,2
    val.clear();
    for (auto v : out)
        val.push_back(std::stoi(v));
    // DUMP("vec", in, val);
}
void ParseArg(const std::string& in, vector<string>& val) {
    vector<string> out;
    fn::Split(out, rb(in), ",");  // remove bracket ["a","b"] -> "a","b"
    val.clear();
    for (auto v : out)
        val.push_back(rq(v));  // remove quota "abc" -> abc
    // DUMP("vecstr", in, val);
}
void ParseArg(const std::string& in, vector<vector<int>>& val) {
    vector<string> out;
    fn::Split(out, rb(in), "],[");  // remove bracket [[1,2],[3],[]] -> [1,2 / 3 / _]
    out[0] = out[0].substr(1);  // first: [1,2 -> 1,2;  if only one element: [1,2] -> 1,2]
    auto& last = out[out.size()-1];  // last: 1,2] -> 1,2
    last.resize(last.size()-1);  // 1,2] -> 1,2
    val.clear();
    for (auto v : out) {
        vector<int> val2;
        vector<string> out2;
        fn::Split(out2, v, ",");
        for (auto v2 : out2)
            val2.push_back(std::stoi(v2));
        val.push_back(val2);
    }
    // DUMP("vecvec", in, val);
}
void ParseArg(const std::string& in, vector<vector<string>>& val) {
    vector<string> out;
    fn::Split(out, rb(in), "],[");  // remove bracket [["A","B"],["C"],[]] -> ["A","B" / "C" / _]
    out[0] = out[0].substr(1);  // first: ["A","B" -> "A","B";  if only one element: "A","B" -> "A","B"]
    auto& last = out[out.size()-1];  // last: "A","B"] -> "A","B"
    last.resize(last.size()-1);  // "A","B"] -> "A","B"
    val.clear();
    for (auto v : out) {
        vector<string> val2;
        vector<string> out2;
        fn::Split(out2, v, ",");
        for (auto v2 : out2)
            val2.push_back(rq(v2));
        val.push_back(val2);
    }
    // DUMP("vecvecstr", in, val);
}
template <typename... Args>
void ParseIn(const vector<string>& in, int idx, Args... args) {}
template <typename T>
void ParseIn(const vector<string>& in, int idx, T& val) {
    ParseArg(in[idx], val);
}
template <typename T, typename... Args>
void ParseIn(const vector<string>& in, int idx, T& val, Args... args) {
    ParseArg(in[idx], val); 
    ParseIn(in, idx+1, args...);
}

}
