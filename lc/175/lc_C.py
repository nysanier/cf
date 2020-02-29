from typing import List
import logging

class TweetCounts:

    def __init__(self):
        self.ss = {}

    def recordTweet(self, tweetName: str, time: int) -> None:
        # logging.error('record(name:%s, time:%s)' % (tweetName, time))
        if not tweetName in self.ss:
            self.ss[tweetName] = []
        l = self.ss[tweetName]
        l.append(time)

    def getTweetCountsPerFrequency(self, freq: str, tweetName: str, startTime: int, endTime: int) -> List[int]:
        # logging.error('get(freq:%s, name:%s, start:%s, end:%s)' % (freq, tweetName, startTime, endTime))
        d = 0
        if freq == 'minute':
            d = 60
        elif freq == 'hour':
            d = 3600
        else:
            d = 3600 * 24
        l = self.ss[tweetName]
        # logging.error('l=%s' % l)
        # t1 = startTime
        # t2 = min(t1 + d - 1, endTime)
        sz = (endTime-startTime+1 + d-1) // d
        # logging.error('sz:%s' % sz)
        r = [0 for i in range(sz)]
        for e in l:
            if e < startTime or e > endTime:
                continue
            idx = (e - startTime) // d
            # logging.error('e:%s, idx:%s' %(e, idx))
            r[idx] += 1
        return r



# Your TweetCounts object will be instantiated and called as such:
# obj = TweetCounts()
# obj.recordTweet(tweetName,time)
# param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime)


if __name__ == "__main__":
    l = ["TweetCounts","recordTweet","recordTweet","recordTweet","getTweetCountsPerFrequency","getTweetCountsPerFrequency","recordTweet","getTweetCountsPerFrequency"]
    l2 = [[],["tweet3",0],["tweet3",60],["tweet3",10],["minute","tweet3",0,59],["minute","tweet3",0,60],["tweet3",120],["hour","tweet3",0,210]]

    obj = None
    for i, e in enumerate(l):
        if e == 'TweetCounts':
            obj = TweetCounts()
        elif e == 'recordTweet':
            obj.recordTweet(*l2[i])
        else:
            r = obj.getTweetCountsPerFrequency(*l2[i])
            print('r = %s' % r)
