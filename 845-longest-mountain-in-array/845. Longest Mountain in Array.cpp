class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int ans = 0;
        int l=0,r=1,n=nums.size();
        bool up=false;
        bool down=false;
        while(r<n){
            while(r<n and nums[r]>nums[r-1]){
                up=true;
                r++;
            }
            while(r<n and nums[r]<nums[r-1]){
                r++;
                down=true;
            }
            if(up and down and r-l>2){
                ans = max(ans,r-l);
            }
            up=down=false;
            while(r<n and nums[r]==nums[r-1])r++;
            l=r-1;
        }
        return ans;
    }
};