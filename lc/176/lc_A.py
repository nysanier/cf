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

if __name__ == "__main__":
    import parse_input as fn
    t, lin, lout = fn.parse_input()
    for i in range(t):
        sol = Solution()
        f = lin[i]
        fout = lout[i]

        # TODO 修改下面2行, 和函数参数匹配即可！
        args = [ f['grid'] ]
        r = sol.countNegatives(*args)

        # 查看结果
        print('out = %s; r = %s' % (fout, r))

