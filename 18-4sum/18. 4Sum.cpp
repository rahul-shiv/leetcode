class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0;i<n-3;i++){
            if(nums[i]>0 and nums[i]>target)return ans;
            if(i and nums[i]==nums[i-1])continue;
            for(int j = i+1;j<n-2;j++){
                if(nums[i]+nums[j]>0 and nums[i]+nums[j]>target)break;
                if(j>i+1 and nums[j]==nums[j-1])continue;
                int l = j+1, r = n-1;
                while(l<r){
                    long long s = (long long)nums[i]+nums[j]+nums[l]+nums[r];
                    if(s==target){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                    }
                    if(nums[l]==nums[r])break;
                    if(s>target){
                        r--;
                        while(r>l and nums[r+1]==nums[r])r--;
                    }
                    else {
                        l++;
                        while(l<r and nums[l-1]==nums[l])l++;
                    }
                }
            }
        }
        return ans;
    }
};