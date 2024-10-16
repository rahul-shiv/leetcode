class Solution {
    vector<vector<int>> ans;
    int n;
    void solve(vector<int>& nums,int i,vector<int>& t){
        if(i==n){
            ans.push_back(t);
            return;
        }
        t.push_back(nums[i]);
        solve(nums,i+1,t);
        t.pop_back();
        if(!i or nums[i]!=nums[i-1]){
            solve(nums,i+1,t);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> t;
        solve(nums,0,t);
        return ans;
    }
};