class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2)return false;
        unordered_map<int,int> m;
        int n = nums.size();
        int s = 0,ts=0;
        for(int i = 0;i<n;i++){
            ts = (ts+nums[i])%k;
            if(m[ts])return true;
            m[s]+=1;
            s=ts;
        }
        return false;
    }
};