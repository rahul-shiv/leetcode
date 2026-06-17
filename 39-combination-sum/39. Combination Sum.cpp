class Solution {
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int target, int i, vector<int> &curr){
        if(target<0 or i>=candidates.size())return;
        if(target==0){
            ans.emplace_back(curr);
            return;
        }
        curr.push_back(candidates[i]);
        solve(candidates,target-candidates[i],i,curr);
        curr.pop_back();
        solve(candidates,target,i+1,curr);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        solve(candidates, target, 0, v);
        return ans;
    }
};