class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(),nums.end(),0);
        if(s%2)return false;
        s/=2;
        vector<bool> dp(s+1,false);
        dp[0]=true;
        for(int i = 0;i<nums.size();i++){
            for(int j = s;j>=0;j--){
                if(dp[j] and j+nums[i]==s){
                    return true;
                }
                else if(dp[j] and j+nums[i]<s){
                    dp[j+nums[i]]=1;
                }
            }
        }
        return false;
    }
};