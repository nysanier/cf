import heapq

class Solution(object):

    def maxEvents(self, A):
        """
        :type events: List[List[int]]
        :rtype: int
        """
        end = []
        A.sort(reverse=True)
        print('A=%s' % A)
        res = 0
        # for i in range(1, 100010):
        for i in range(1, 10):
            while A and A[-1][0] == i:  # 取最小的一个pair.second(end)
                heapq.heappush(end, A.pop()[1])
            while end and end[0] < i:  # 过小的值不要！
                heapq.heappop(end)
            if end:  # 满足当前要求
                heapq.heappop(end)
                res += 1
            def dump():
                print('i=%s; res=%s;' % (i,res))
                print('    A=%s; end=%s;' % (A, end))
            dump()
        return res

s = Solution()
l = [[1,2],[1,2],[3,3],[1,5],[1,5]]
r = s.maxEvents(l)
print('r = %s' % r)
