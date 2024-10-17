class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxsofar=0, n = nums.size(), i =0;
        for(i = 0;i<=min(maxsofar,n-1);i++){
            maxsofar = max(maxsofar,i+nums[i]);
        }
        return i==n;
    }
};