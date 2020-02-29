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
    l = ["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
    l2 = [[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

    obj = None
    for i, e in enumerate(l):
        if e == 'ProductOfNumbers':
            obj = ProductOfNumbers()
        elif e == 'add':
            obj.add(*l2[i])
        else:
            r = obj.getProduct(*l2[i])
            print('r = %s' % r)


