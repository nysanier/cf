from typing import List
import collections

class Solution:
    def minSteps(self, s: str, t: str) -> int:
        a = collections.Counter(s)
        b = collections.Counter(t)
        sum_of_common = 0
        for k in a:
            # won't return KeyError, but 0
            sum_of_common += min(a[k], b[k])
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

