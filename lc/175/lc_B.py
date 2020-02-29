from typing import List

class Solution:
    def plus(self, d, c):
        if not c in d:
            d[c] = 1
        else:
            d[c] += 1

    def get(self, d, c):
        if not c in d:
            return 0
        else:
            return d[c]

    def minSteps(self, s: str, t: str) -> int:
        sd = {}
        for c in s:
            self.plus(sd, c)
        td = {}
        for c in t:
            self.plus(td, c)
        # 一样的私募个数
        sum_of_common = 0
        for k, v in sd.items():
            v2 = self.get(td, k)
            sum_of_common += min(v, v2)
        r = len(s) - sum_of_common
        return r

str_input = '''5
示例 1：

输入：s = "bab", t = "aba"
输出：1
提示：用 'b' 替换 t 中的第一个 'a'，t = "bba" 是 s 的一个字母异位词。
示例 2：

输入：s = "leetcode", t = "practice"
输出：5
提示：用合适的字符替换 t 中的 'p', 'r', 'a', 'i' 和 'c'，使 t 变成 s 的字母异位词。
示例 3：

输入：s = "anagram", t = "mangaar"
输出：0
提示："anagram" 和 "mangaar" 本身就是一组字母异位词。 
示例 4：

输入：s = "xxyyzz", t = "xxyyzz"
输出：0
示例 5：

输入：s = "friend", t = "family"
输出：4

'''

if __name__ == "__main__":
    import os, sys
    sys.path.append('/Users/nysanier/git/cf/lc')
    import fn
    t, lin, lout = fn.parse_input(str_input)
    for i in range(t):
        sol = Solution()
        f = lin[i]
        fout = lout[i]

        # TODO 修改下面这行, 和函数参数匹配即可！
        args = [ f['s'], f['t'] ]
        r = sol.minSteps(*args)

        # 比较结果  
        print('out = %s; r = %s' % (fout, r))

