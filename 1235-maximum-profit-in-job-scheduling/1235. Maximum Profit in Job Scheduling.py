class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        x = sorted(zip(endTime,startTime,profit))
        n = len(x)
        dp = [0]*len(x)
        for i,tup in enumerate(x):
            end,start,profit = tup
            if not i:
                dp[i] = profit
                continue
            f = 0
            j = bisect_right(x,(start,float('inf')))-1
            f = dp[j]
            dp[i] = max(dp[i-1],f+profit)
            
        return dp[-1]