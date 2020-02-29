from typing import List

class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        r = 0
        # for row in grid:
        #     for v in row:
        #         r += 1 if v < 0 else 0
        for row in grid:
            # (v for v in row) 是generator, 也就是iterable
            r += sum(v < 0 for v in row)
        return r


str_input = '''4
示例 1：

输入：grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
输出：8
解释：矩阵中共有 8 个负数。
示例 2：

输入：grid = [[3,2],[1,0]]
输出：0
示例 3：

输入：grid = [[1,-1],[-1,-1]]
输出：3
示例 4：

输入：grid = [[-1]]
输出：1

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

        # TODO 修改下面2行, 和函数参数匹配即可！
        args = [ f['grid'] ]
        r = sol.countNegatives(*args)

        # 查看结果
        print('out = %s; r = %s' % (fout, r))

