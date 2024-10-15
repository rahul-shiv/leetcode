class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        int ans = 0;
        m[0]=1;
        for(int i =0; i<nums.size();i++){
            if(i)nums[i]+=nums[i-1];
            auto it = m.find(nums[i]-k);
            if(it!=m.end())ans+=it->second;
            m[nums[i]]++;
        }
        return ans;
    }
};