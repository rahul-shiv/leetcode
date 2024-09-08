class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1e4+1);
        dp[0]=0;
        int sf=1;
        for(int i = 0;i<n;i++){
            for(;sf<min(n,i+nums[i]+1);sf++){
                dp[sf]=dp[i]+1;
            }
        }
        return dp[n-1];
    }
};