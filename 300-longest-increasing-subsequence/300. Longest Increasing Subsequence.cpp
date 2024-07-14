class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(auto num:nums){
            auto it = lower_bound(ans.begin(), ans.end(), num);
            if(it!=ans.end()){
                *it=num;
            }else{
                ans.push_back(num);
            }
        }
        return ans.size();
    }
};