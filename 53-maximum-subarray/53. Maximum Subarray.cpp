class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e4-1, s = -1e4-1;
        for(auto num:nums){
            s = max(num,s+num);
            ans = max(ans,s);
        }
        return ans;
    }
};