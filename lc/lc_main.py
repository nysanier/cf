from typing import List

class Solution:
    def test(self, arg0):
        return 0

str_input = '''1

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
        r = sol.test(*args)

        # 比较结果  
        print('out = %s; r = %s' % (fout, r))


# if __name__ == "__main__":
#     l = ["TweetCounts","recordTweet","recordTweet","recordTweet","getTweetCountsPerFrequency","getTweetCountsPerFrequency","recordTweet","getTweetCountsPerFrequency"]
#     l2 = [[],["tweet3",0],["tweet3",60],["tweet3",10],["minute","tweet3",0,59],["minute","tweet3",0,60],["tweet3",120],["hour","tweet3",0,210]]

#     obj = None
#     for i, e in enumerate(l):
#         if e == 'TweetCounts':
#             obj = TweetCounts()
#         elif e == 'recordTweet':
#             obj.recordTweet(*l2[i])
#         else:
#             r = obj.getTweetCountsPerFrequency(*l2[i])
#             print('r = %s' % r)
