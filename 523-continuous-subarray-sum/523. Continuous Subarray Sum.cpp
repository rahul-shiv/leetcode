class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> x;
        x[0]++;
        for(int i = 1;i<nums.size();i++){
            nums[i]+=nums[i-1];
            if(x[nums[i]%k])return true;
            x[nums[i-1]%k]++;
        }

        return false;
    }
};