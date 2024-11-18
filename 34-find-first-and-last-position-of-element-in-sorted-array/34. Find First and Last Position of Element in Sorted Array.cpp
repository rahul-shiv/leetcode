class Solution {
    int lb(vector<int>& nums, int target, bool exact=false){
        int l = 0, r= nums.size(),m;
        while(l<r){
            m = l+(r-l)/2;
            if(nums[m]>target or (exact and nums[m]==target))r=m;
            else l=m+1;
        }
        return l;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = lb(nums,target,true);
        if(l==nums.size() or nums[l]!=target)return {-1,-1};
        return {l,max(l,lb(nums,target)-1)};
    }
};