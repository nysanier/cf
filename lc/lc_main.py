from typing import List

class Solution:
    def test(self, arg0):
        pass

if __name__ == "__main__":
    import parse_input as fn
    t, lin, lout = fn.parse_input()
    for i in range(t):
        sol = Solution()
        f = lin[i]
        fout = lout[i]

        # TODO 修改下面这行, 和函数参数匹配即可！
        args = [ f['events'] ]
        r = sol.test(*args)

        # 比较结果  
        print('out = %s; r = %s' % (fout, r))

