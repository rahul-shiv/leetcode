class Solution {
    void solve(vector<int> &can, vector<vector<int>> &ans, vector<int> &t, int target, int i){
        if(i==can.size())return;
        if(target==0){
            ans.push_back(t);
            return;
        }
        if(can[i]<=target){
            solve(can, ans, t, target, i+1);
            t.push_back(can[i]);
            solve(can, ans, t, target-can[i], i);
            t.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        sort(can.begin(),can.end());
        int n = can.size();
        vector<vector<int>> ans;
        vector<int> t;
        solve(can, ans, t, target, 0);
        return ans;
    }
};