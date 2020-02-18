from typing import List

class ProductOfNumbers:
    def __init__(self):
        self.A = [1]

    def add(self, a):
        if a == 0:
            self.A = [1]
        else:
            self.A.append(self.A[-1] * a)

    # 暴力计算乘法！
    def getProduct(self, k):
        if k >= len(self.A): return 0
        r = self.A[-1] / self.A[-k-1]
        return int(r)
        


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)

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

