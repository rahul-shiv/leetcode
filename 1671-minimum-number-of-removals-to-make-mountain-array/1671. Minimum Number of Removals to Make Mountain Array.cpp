class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> lis;
        vector<int> dp(n);
        for(int i = 0;i<n;i++){
            auto it = lower_bound(lis.begin(),lis.end(),nums[i]);
            if(it==lis.end()){
                lis.push_back(nums[i]);
            }else{
                *it=nums[i];
            }
            dp[i]=lis.size();
        }
        lis = vector<int>();
        int k;
        for(int i = n-1; i>0;i--){
            auto it = lower_bound(lis.begin(),lis.end(),nums[i]);
            if(it==lis.end()){
                lis.push_back(nums[i]);
            }else{
                *it=nums[i];
            }
            if(dp[i]>1 and lis.size()>1)ans = min(ans, n - (dp[i]+(int)lis.size()-1));
        }
        return ans;
    }
};