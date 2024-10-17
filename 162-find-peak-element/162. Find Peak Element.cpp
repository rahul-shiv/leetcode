class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1, m;
        if(r==0)return 0;
        if(nums[l]>nums[l+1])return l;
        if(nums[r]>nums[r-1])return r;
        l++;
        r--;
        while(l<r){
            m = l+(r-l)/2;
            if(nums[m]>nums[m+1]){
                r=m;
            }else{
                l=m+1;
            }
        }
        return l;
    }
};