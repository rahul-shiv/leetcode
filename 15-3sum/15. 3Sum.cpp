class Solution {
public:
    #define SUM3 (nums[l]+nums[r]+nums[i])
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size(),l,r;
        for(int i = 0; i < n-2; i++){
            if(i and nums[i]==nums[i-1]){
                continue;
            }
            l=i+1;
            r = n-1;
            while(l<r){
                if(SUM3==0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    
                }
                if(SUM3<=0){
                    l++;
                    while(l<r and nums[l]==nums[l-1]){
                        l++;
                    }
                }else{
                    r--;
                    while(l<r and nums[r]==nums[r+1]){
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};