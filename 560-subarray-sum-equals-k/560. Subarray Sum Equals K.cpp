class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]=1;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            if(i){
                nums[i]+=nums[i-1];
            }
            if(m[nums[i]-k]){
                ans+=m[nums[i]-k];
            }
            m[nums[i]]++;
        }
        return ans;
    }
};