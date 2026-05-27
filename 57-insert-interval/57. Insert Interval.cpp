class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0, n = intervals.size();
        for(i = 0; i<n;i++){
            if(newInterval[0]<=intervals[i][1])break;
            ans.push_back(intervals[i]);
        }
        if(i==n)ans.push_back(newInterval);
        else {
            if(newInterval[1]<intervals[i][0]){
                ans.push_back(newInterval);
            }
            else ans.push_back({min(newInterval[0],intervals[i][0]), max(newInterval[1], intervals[i][1])});
        }
        while(i<n and ans.back()[1]>=intervals[i][0])ans.back()[1]=max(intervals[i++][1],ans.back()[1]);
        while(i<n) ans.push_back(intervals[i++]);
        return ans;
    }
};