"""
# Definition for an Interval.
class Interval:
    def __init__(self, start: int = None, end: int = None):
        self.start = start
        self.end = end
"""

class Solution:
    def employeeFreeTime(self, schedule: '[[Interval]]') -> '[Interval]':
        def f(y):
            print('[',y.start,y.end,'], ',end = ' ')
        def findFree(sched):
            ret = [Interval(float('-inf'),sched[0].start)]
            for i in range(1,len(sched)):
                ret.append(Interval(sched[i-1].end,sched[i].start))
            ret.append(Interval(sched[-1].end,float('inf')))
            return ret
        freeSchedule = []
        for sched in schedule:
            freeSchedule.append(findFree(sched))
        def merge(x,y):
            ret = []
            for z in x:
                f(z)
            print()
            for z in y:
                f(z)
            print()
            for i in x:
                for j in y:
                    if i.end<j.start or i.start>j.end :
                        continue
                    else:
                        ret.append(Interval(max(i.start,j.start),min(i.end,j.end)))
            print("=====")
            for z in ret:
                f(z)
            print("\n=====")
            return ret
        ans = freeSchedule[0]
        for i in range(1,len(freeSchedule)):
            ans = merge(ans,freeSchedule[i])
        ans = ans[1:-1]
        ans2 = []
        for x in ans:
            if x.start<x.end:
                ans2.append(x)
        return ans2
                