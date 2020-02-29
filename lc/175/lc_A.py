from typing import List

class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        for i, a in enumerate(arr):
            for j, b in enumerate(arr):
                if i!=j and a==b*2:
                    return True
        return False


str_input = '''3
示例 1：

输入：arr = [10,2,5,3]
输出：True
解释：N = 10 是 M = 5 的两倍，即 10 = 2 * 5 。
示例 2：

输入：arr = [7,1,14,11]
输出：True
解释：N = 14 是 M = 7 的两倍，即 14 = 2 * 7 。
示例 3：

输入：arr = [3,1,7,11]
输出：False
解释：在该情况下不存在 N 和 M 满足 N = 2 * M 。

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
        args = [ f['arr'] ]
        r = sol.checkIfExist(*args)

        # 比较结果
        print('out = %s; r = %s' % (fout, r))

