class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int x = 0;
        int ans = 0,l =0, r=0, n = nums.size();
        while(r<n){
            while(r<n and (x<k or nums[r])){
                if(nums[r]==0)x++;
                r++;
            }
            ans = max(ans,r-l);
            while(l<r and x==k){
                if(nums[l]==0)x--;
                l++;
            }
            if(l==r){
                l++;
                r++;
            }
        }
        return ans;
    }
};