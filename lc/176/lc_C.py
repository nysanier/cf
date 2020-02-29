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


str_input = '''5
示例 1：

输入：events = [[1,2],[2,3],[3,4]]
输出：3
解释：你可以参加所有的三个会议。
安排会议的一种方案如上图。
第 1 天参加第一个会议。
第 2 天参加第二个会议。
第 3 天参加第三个会议。
示例 2：

输入：events= [[1,2],[2,3],[3,4],[1,2]]
输出：4
示例 3：

输入：events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
输出：4
示例 4：

输入：events = [[1,100000]]
输出：1
示例 5：

输入：events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
输出：7

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
        args = [ f['events'] ]
        r = sol.maxEvents(*args)
    
        print('out = %s; r = %s' % (fout, r))

