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


if __name__ == "__main__":
    import parse_input as fn
    t, lin, lout = fn.parse_input()
    for i in range(t):
        sol = Solution()
        f = lin[i]
        fout = lout[i]

        # TODO 修改下面这行, 和函数参数匹配即可！
        args = [ f['s'], f['t'] ]
        r = sol.minSteps(*args)

        # 比较结果  
        print('out = %s; r = %s' % (fout, r))

