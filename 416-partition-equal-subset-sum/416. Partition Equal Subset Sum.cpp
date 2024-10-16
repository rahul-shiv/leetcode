class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(),nums.end(),0);
        if(s%2)return false;
        s/=2;
        set<int> dp;
        dp.insert(0);
        for(int i = 0;i<nums.size();i++){
            for(auto it = dp.rbegin();it!=dp.rend();it++){
                if(*it+nums[i]==s){
                    return true;
                }
                else if(*it+nums[i]<s){
                    dp.insert(*it+nums[i]);
                }
            }
        }
        return false;
    }
};