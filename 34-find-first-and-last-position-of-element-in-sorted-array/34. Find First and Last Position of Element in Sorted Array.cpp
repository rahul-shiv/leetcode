class Solution {
    int lb(vector<int>& nums, int target){
        int l = 0, r= nums.size()-1,m;
        while(l<r){
            m = l+(r-l)/2;
            if(nums[m]<target)l=m+1;
            else r=m;
        }
        if(l<nums.size() and nums[l]<target)l++; 
        return l;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = lb(nums,target);
        if(l==nums.size() or nums[l]!=target)return {-1,-1};
        return {l,max(l,lb(nums,target+1)-1)};
    }
};