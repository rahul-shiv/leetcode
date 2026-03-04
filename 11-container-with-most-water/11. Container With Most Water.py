class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height)-1
        ans = 0
        while l<=r:
            curr = min(height[l],height[r])*(r-l)
            if height[l]<height[r]:
                l+=1
            else:
                r-=1
            ans = max(ans,curr)
        return ans