class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 1;
        while(r<nums.size()){
            nums[l+1]=nums[r];
            l++;
            r++;
            if(nums[r-1]==nums[l-1]){
                while(r<nums.size() and nums[r]==nums[l])r++;
            }
        }
        return l+1;
    }
};