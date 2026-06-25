class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(),nums.end(),0);
        if(s%2)return false;
        s/=2;
        set<int> ans;
        ans.insert(0);
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size();i++){
            for(auto x=ans.rbegin();x!=ans.rend();x++){
                if(*x+nums[i]==s)return true;
                ans.insert(*x+nums[i]);
            }
        }
        return false;
    }
};