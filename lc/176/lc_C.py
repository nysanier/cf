import heapq
from typing import List

class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        end = []
        events.sort(reverse=True)  # 倒排为了pop！
        r = 0
        for i in range(1, int(1e5)+1):
            # 取所有当前满足条件的 pair
            while events and events[-1][0] == i:
                kv = events.pop()
                heapq.heappush(end, kv[1])
            # 淘汰所有已经无法满足的 end
            while end and end[0] < i:
                heapq.heappop(end)
            if end:  # 贪心，取一个最小的满足当前要求的 end
                heapq.heappop(end)
                r += 1
        return r


if __name__ == "__main__":
    import parse_input as fn
    t, lin, lout = fn.parse_input()
    for i in range(t):
        sol = Solution()
        f = lin[i]
        fout = lout[i]

        # TODO 修改下面这行, 和函数参数匹配即可！
        args = [ f['events'] ]
        r = sol.maxEvents(*args)
    
        print('out = %s; r = %s' % (fout, r))

