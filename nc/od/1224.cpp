/*
输入示例
3
Zhangsan Huawei
Lisi zhongxing
Wangwu ailixin
6
Zhangsan
Lisi
Wangwu
Zhangsan
Zhangsan
Lisi

输出示例
Huawei
*/









// 题目对输出没有描述，示例给的不够清晰，如果有多个同样选票的人，如何输出？
// 选举人的数量范围也没有作出说明或者限制
// 题目没有说明，如果最后选票结果一样，但是有多个人，那么输出多个公司？
// 这里假设n/m的范围在32bits内

#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>

/*
Case 2
4
Zhangsan Huawei
Lisi zhongxing
Zhangsan ailixin
Wangwu ailixin
8
Zhangsan
Lisi
Zhangsan
Zhangsan
Zhangsan
Wangwu
Lisi
Wangwu

*/


template <typename C>
void Dump(const C& c) {
    // std::cerr << "dump: {";
    // for (auto kv : c) {
    //     std::cerr << "<" << kv.first << "," << kv.second << ">,";
    // }
    // std::cerr << "}" << std::endl;
}

// 40%
// 同一个公司不能重复
void solve1();

// 60%
// 同一个人不能重复
void solve2();

// 60%
// 名字存在大小写？
void solve3();

// 60%
// 假设只输出最后一个候选人的公司？
void solve4();

// 60%
// 存在64bits？
void solve5();

// 60%
// 简化invalid
// p2c在多个case下有问题？
void solve6();

// 40%
// 如果让有争议的候选人有效，结果如何？
void solve7();

// 60%
// 同一个公司可以重复是吧？
void solve8();

// 不会是empty vote有问题吧？
void solve9();

// 代表的后面的公司无效？
void solve10();

int main() {
    solve9();

    return 0;
}

void solve10() {
    int n;
    while (std::cin >> n) {
        std::map<std::string, std::vector<std::string>> p2c;  // 候选人对应的公司
        std::string name, company;
        for (int i = 0; i < n; ++i) {
            std::cin >> name >> company;
            p2c[name].push_back(company);
        }
        Dump(p2c);

        std::map<std::string, int> vote;
        for (auto kv : p2c) {
            // 有效候选人，准备投票
            vote[kv.first] = 0;
        }

        // 只为有效候选人投票
        int m;
        std::cin >> m;
        std::string name2;
        for (int i = 0; i < m; ++i) {
            std::cin >> name2;
            if (vote.find(name2) != vote.end()) {
                vote[name2] += 1;
            }
        }
        Dump(vote);

        // 可能有这个情况?
        if (vote.empty()) {
            // std::cerr << "no result" << std::endl;
            continue;
        }

        // 多个候选人票一样？
        std::multimap<int, std::string> res;
        for (auto kv : vote) {
            res.insert({kv.second, kv.first});
        }
        auto maxv = (--res.end())->first;  // 最高的票数
        auto it1 = res.lower_bound(maxv);  // 所有获得最高票数的人
        auto it2 = res.upper_bound(maxv);
        for (auto it = it1; it != it2; ++it) {
            auto p = it->second;  // 候选人
            auto c = p2c[p][0];  // 候选人所在公司
            std::cout << c << std::endl;
        }
    }
}

void solve9() {
    int n;
    while (std::cin >> n) {
        std::map<std::string, std::set<std::string>> p2c;  // 候选人对应的公司
        std::string name, company;
        for (int i = 0; i < n; ++i) {
            std::cin >> name >> company;
            p2c[name].insert(company);
        }
        Dump(p2c);

        std::map<std::string, int> vote;
        for (auto kv : p2c) {
            if (kv.second.size() > 1u) {  // 此人在多个公司出现，无效
                continue;
            }
            // 有效候选人，准备投票
            vote[kv.first] = 0;
        }

        // 只为有效候选人投票
        int m;
        std::cin >> m;
        std::string name2;
        for (int i = 0; i < m; ++i) {
            std::cin >> name2;
            if (vote.find(name2) != vote.end()) {
                vote[name2] += 1;
            }
        }
        Dump(vote);

        // 可能有这个情况?
        if (vote.empty()) {
            // std::cerr << "no result" << std::endl;
            continue;
        }

        // 多个候选人票一样？
        std::multimap<int, std::string> res;
        for (auto kv : vote) {
            res.insert({kv.second, kv.first});
        }
        auto maxv = (--res.end())->first;  // 最高的票数
        auto it1 = res.lower_bound(maxv);  // 所有获得最高票数的人
        auto it2 = res.upper_bound(maxv);
        for (auto it = it1; it != it2; ++it) {
            auto p = it->second;  // 候选人
            auto c = *p2c[p].begin();  // 候选人所在公司
            std::cout << c << std::endl;
        }
    }
}

void solve8() {
    int n;
    while (std::cin >> n) {
        std::map<std::string, std::set<std::string>> p2c;  // 候选人对应的公司
        std::string name, company;
        for (int i = 0; i < n; ++i) {
            std::cin >> name >> company;
            p2c[name].insert(company);
        }
        Dump(p2c);

        std::map<std::string, int> vote;
        for (auto kv : p2c) {
            if (kv.second.size() > 1u) {  // 此人在多个公司出现，无效
                continue;
            }
            // 有效候选人，准备投票
            vote[kv.first] = 0;
        }

        // 只为有效候选人投票
        int m;
        std::cin >> m;
        std::string name2;
        for (int i = 0; i < m; ++i) {
            std::cin >> name2;
            if (vote.find(name2) != vote.end()) {
                vote[name2] += 1;
            }
        }
        Dump(vote);

        // 可能有这个情况?
        if (vote.empty()) {
            std::cerr << "no result" << std::endl;
            continue;
        }

        // 多个候选人票一样？
        std::multimap<int, std::string> res;
        for (auto kv : vote) {
            res.insert({kv.second, kv.first});
        }
        auto maxv = (--res.end())->first;  // 最高的票数
        auto it1 = res.lower_bound(maxv);  // 所有获得最高票数的人
        auto it2 = res.upper_bound(maxv);
        for (auto it = it1; it != it2; ++it) {
            auto p = it->second;  // 候选人
            auto c = *p2c[p].begin();  // 候选人所在公司
            std::cout << c << std::endl;
        }
    }
}

void solve7() {
    int n;
    while (std::cin >> n) {
        std::map<std::string, std::vector<std::string>> p2c;  // 候选人对应的公司
        std::string name, company;
        for (int i = 0; i < n; ++i) {
            std::cin >> name >> company;
            p2c[name].push_back(company);
        }
        Dump(p2c);

        std::map<std::string, int> vote;
        for (auto kv : p2c) {
            // 有效候选人，准备投票
            vote[kv.first] = 0;
        }

        // 只为有效候选人投票
        int m;
        std::cin >> m;
        std::string name2;
        for (int i = 0; i < m; ++i) {
            std::cin >> name2;
            if (vote.find(name2) != vote.end()) {
                vote[name2] += 1;
            }
        }
        Dump(vote);

        // 可能有这个情况?
        if (vote.empty()) {
            std::cerr << "no result" << std::endl;
            continue;
        }

        // 多个候选人票一样？
        std::multimap<int, std::string> res;
        for (auto kv : vote) {
            res.insert({kv.second, kv.first});
        }
        auto maxv = (--res.end())->first;  // 最高的票数
        auto it1 = res.lower_bound(maxv);  // 所有获得最高票数的人
        auto it2 = res.upper_bound(maxv);
        for (auto it = it1; it != it2; ++it) {
            auto p = it->second;  // 候选人
            auto c = p2c[p][0];  // 候选人所在公司
            std::cout << c << std::endl;
        }
    }
}

void solve6() {
    int n;
    while (std::cin >> n) {
        std::map<std::string, std::vector<std::string>> p2c;  // 候选人对应的公司
        std::string name, company;
        for (int i = 0; i < n; ++i) {
            std::cin >> name >> company;
            p2c[name].push_back(company);
        }
        Dump(p2c);

        std::map<std::string, int> vote;
        for (auto kv : p2c) {
            if (kv.second.size() > 1u) {  // 同一个人在多个公司，则忽略其选票
                continue;
            }

            // 有效候选人，准备投票
            vote[kv.first] = 0;
        }

        // 只为有效候选人投票
        int m;
        std::cin >> m;
        std::string name2;
        for (int i = 0; i < m; ++i) {
            std::cin >> name2;
            if (vote.find(name2) != vote.end()) {
                vote[name2] += 1;
            }
        }
        Dump(vote);

        // 可能有这个情况?
        if (vote.empty()) {
            std::cerr << "no result" << std::endl;
            continue;
        }

        // 多个候选人票一样？
        std::multimap<int, std::string> res;
        for (auto kv : vote) {
            res.insert({kv.second, kv.first});
        }
        auto maxv = (--res.end())->first;  // 最高的票数
        auto it1 = res.lower_bound(maxv);  // 所有获得最高票数的人
        auto it2 = res.upper_bound(maxv);
        for (auto it = it1; it != it2; ++it) {
            auto p = it->second;  // 候选人
            auto c = p2c[p][0];  // 候选人所在公司
            std::cout << c << std::endl;
        }
    }
}

void solve5() {
    std::map<std::string, std::string> p2c;
    std::set<std::string> invalid;
    long long n;
    while (std::cin >> n) {
        std::string name, company;
        for (long long i = 0; i < n; ++i) {
            std::cin >> name >> company;
            if (p2c.find(name) != p2c.end()) {  // 候选人在不同公司间重复
                invalid.insert(name);  // 那么这个候选人无效
            } else {
                p2c[name] = company;
            }
        }
        Dump(p2c);

        std::map<std::string, long long> vote;
        for (auto kv : p2c) {
            if (invalid.find(kv.first) != invalid.end()) {  // 候选人无效，则不为其投票
                continue;
            }

            // 有效候选人，准备投票
            vote[kv.first] = 0;
        }

        // 只为有效候选人投票
        long long m;
        std::cin >> m;
        std::string name2;
        for (long long i = 0; i < m; ++i) {
            std::cin >> name2;
            if (vote.find(name2) != vote.end()) {
                vote[name2] += 1;
            }
        }
        Dump(vote);

        // 可能有这个情况?
        if (vote.empty()) {
            std::cerr << "no result" << std::endl;
            continue;
        }

        // 多个候选人票一样？
        std::multimap<long long, std::string> res;
        for (auto kv : vote) {
            res.insert({kv.second, kv.first});
        }
        auto maxv = (--res.end())->first;  // 最高的票数
        auto it1 = res.lower_bound(maxv);  // 所有获得最高票数的人
        auto it2 = res.upper_bound(maxv);
        for (auto it = it1; it != it2; ++it) {
            auto p = it->second;  // 候选人
            auto c = p2c[p];  // 候选人所在公司
            std::cout << c << std::endl;
        }
    }
}

void solve4() {
    std::map<std::string, std::string> p2c;
    std::set<std::string> invalid;
    int n;
    while (std::cin >> n) {
        std::string name, company;
        for (int i = 0; i < n; ++i) {
            std::cin >> name >> company;
            if (p2c.find(name) != p2c.end()) {  // 候选人在不同公司间重复
                invalid.insert(name);  // 那么这个候选人无效
            } else {
                p2c[name] = company;
            }
        }
        Dump(p2c);

        std::map<std::string, int> vote;
        for (auto kv : p2c) {
            if (invalid.find(kv.first) != invalid.end()) {  // 候选人无效，则不为其投票
                continue;
            }

            // 有效候选人，准备投票
            vote[kv.first] = 0;
        }

        // 只为有效候选人投票
        int m;
        std::cin >> m;
        std::string name2;
        for (int i = 0; i < m; ++i) {
            std::cin >> name2;
            if (vote.find(name2) != vote.end()) {
                vote[name2] += 1;
            }
        }
        Dump(vote);

        // 可能有这个情况?
        if (vote.empty()) {
            std::cerr << "no result" << std::endl;
            continue;
        }

        // 多个候选人票一样？
        std::multimap<int, std::string> res;
        for (auto kv : vote) {
            res.insert({kv.second, kv.first});
        }
        auto maxv = (--res.end())->first;  // 最高的票数
        // auto it1 = res.lower_bound(maxv);  // 所有获得最高票数的人
        auto it2 = res.upper_bound(maxv);
        {
            auto it = --it2;
            auto p = it->second;  // 候选人
            auto c = p2c[p];  // 候选人所在公司
            std::cout << c << std::endl;
        }
    }
}

std::string ToLower(const std::string& str) {
    std::string res;
    for (auto ch : str) {
        res.push_back(tolower(ch));
    }
    return res;
}
void solve3() {
    std::map<std::string, std::string> p2c;
    std::set<std::string> invalid;
    int n;
    while (std::cin >> n) {
        std::string name, company;
        for (int i = 0; i < n; ++i) {
            std::cin >> name >> company;
            name = ToLower(name);
            if (p2c.find(name) != p2c.end()) {  // 候选人在不同公司间重复
                invalid.insert(name);  // 那么这个候选人无效
            } else {
                p2c[name] = company;
            }
        }
        Dump(p2c);

        std::map<std::string, int> vote;
        for (auto kv : p2c) {
            if (invalid.find(kv.first) != invalid.end()) {  // 候选人无效，则不为其投票
                continue;
            }

            // 有效候选人，准备投票
            vote[kv.first] = 0;
        }

        // 只为有效候选人投票
        int m;
        std::cin >> m;
        std::string name2;
        for (int i = 0; i < m; ++i) {
            std::cin >> name2;
            name2 = ToLower(name2);
            if (vote.find(name2) != vote.end()) {
                vote[name2] += 1;
            }
        }
        Dump(vote);

        // 可能有这个情况?
        if (vote.empty()) {
            std::cerr << "no result" << std::endl;
            continue;
        }

        // 多个候选人票一样？
        std::multimap<int, std::string> res;
        for (auto kv : vote) {
            res.insert({kv.second, kv.first});
        }
        auto maxv = (--res.end())->first;  // 最高的票数
        auto it1 = res.lower_bound(maxv);  // 所有获得最高票数的人
        auto it2 = res.upper_bound(maxv);
        for (auto it = it1; it != it2; ++it) {
            auto p = it->second;  // 候选人
            auto c = p2c[p];  // 候选人所在公司
            std::cout << c << std::endl;
        }
    }
}

void solve2() {
    std::map<std::string, std::string> p2c;
    std::set<std::string> invalid;
    int n;
    while (std::cin >> n) {
        std::string name, company;
        for (int i = 0; i < n; ++i) {
            std::cin >> name >> company;
            if (p2c.find(name) != p2c.end()) {  // 候选人在不同公司间重复
                invalid.insert(name);  // 那么这个候选人无效
            } else {
                p2c[name] = company;
            }
        }
        Dump(p2c);

        std::map<std::string, int> vote;
        for (auto kv : p2c) {
            if (invalid.find(kv.first) != invalid.end()) {  // 候选人无效，则不为其投票
                continue;
            }

            // 有效候选人，准备投票
            vote[kv.first] = 0;
        }

        // 只为有效候选人投票
        int m;
        std::cin >> m;
        std::string name2;
        for (int i = 0; i < m; ++i) {
            std::cin >> name2;
            if (vote.find(name2) != vote.end()) {
                vote[name2] += 1;
            }
        }
        Dump(vote);

        // 可能有这个情况?
        if (vote.empty()) {
            std::cerr << "no result" << std::endl;
            continue;
        }

        // 多个候选人票一样？
        std::multimap<int, std::string> res;
        for (auto kv : vote) {
            res.insert({kv.second, kv.first});
        }
        auto maxv = (--res.end())->first;  // 最高的票数
        auto it1 = res.lower_bound(maxv);  // 所有获得最高票数的人
        auto it2 = res.upper_bound(maxv);
        for (auto it = it1; it != it2; ++it) {
            auto p = it->second;  // 候选人
            auto c = p2c[p];  // 候选人所在公司
            std::cout << c << std::endl;
        }
    }
}

// 40%
void solve1() {
    std::map<std::string, std::string> c2p;
    std::set<std::string> invalid;
    int n;
    while (std::cin >> n) {
        std::string name, company;
        for (int i = 0; i < n; ++i) {
            std::cin >> name >> company;
            if (c2p.find(company) != c2p.end()) {  // 同一个公司存在多个选举人，选举人无效
                invalid.insert(company);
            } else {
                c2p[company] = name;
            }
        }
        Dump(c2p);

        std::map<std::string, std::string> p2c;
        std::map<std::string, int> vote;
        for (auto kv : c2p) {
            if (invalid.find(kv.first) != invalid.end()) {  // 这个公司的候选人选票无效
                continue;
            }

            p2c[kv.second] = kv.first;
            vote[kv.second] = 0;
        }
        Dump(p2c);

        int m;
        std::cin >> m;
        std::string name2;
        for (int i = 0; i < m; ++i) {
            std::cin >> name2;
            if (vote.find(name2) != vote.end()) {
                vote[name2] += 1;
            }
        }
        Dump(vote);

        if (vote.empty()) {
            std::cerr << "no result" << std::endl;
            continue;
        }

        std::multimap<int, std::string> res;
        for (auto kv : vote) {
            res.insert({kv.second, kv.first});
        }
        auto maxv = (--res.end())->first;  // 最高的票数
        auto it1 = res.lower_bound(maxv);  // 所有获得最高票数的人
        auto it2 = res.upper_bound(maxv);
        for (auto it = it1; it != it2; ++it) {
            auto p = it->second;
            auto c = p2c[p];
            std::cout << c << std::endl;
        }
    }
}
