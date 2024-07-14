class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        if(n==3)return max(nums[0]+nums[2],nums[1]);
        vector<int> ans(n);
        ans[0]=nums[0];
        ans[1]=nums[1];
        ans[2]=nums[0]+nums[2];
        for(int i = 3;i < n; i++){
            ans[i]=nums[i]+max(ans[i-2],ans[i-3]);
        }
        return max(ans[n-1],ans[n-2]);
    }
};