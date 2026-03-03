class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(auto interval:intervals){
            if(ans.empty()){
                ans.push_back(interval);
            }else{
                if(ans.back()[1]>=interval[0]){
                    ans.back()[1]=max(interval[1],ans.back()[1]);
                }else{
                    ans.push_back(interval);
                }
            }
        }
        return ans;
    }
};