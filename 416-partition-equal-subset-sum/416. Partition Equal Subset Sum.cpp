class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(),nums.end(),0);
        if(s%2)return false;
        s/=2;
        vector<bool> ans(s+1);
        ans[0]=1;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size();i++){
            for(int j = s;j>=0;j--){
                if(ans[j]==0 or j+nums[i]>s)continue;
                if(j+nums[i]==s)return true;
                ans[j+nums[i]]=true;
            }
        }
        return false;
    }
};