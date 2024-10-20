class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int,int>> v(n+1);
        v[0][0]=1;
        for(int i = 1;i<=n;i++){
            for(auto x:v[i-1]){
                v[i][x.first+nums[i-1]]+=x.second;
                v[i][x.first-nums[i-1]]+=x.second;
            }
        }
        return v.back()[target];
    }
};