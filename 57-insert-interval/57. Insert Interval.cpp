class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if(intervals.empty()){
            ans.push_back(newInterval);
            return ans;
        }
        for(int i = 0; i < intervals.size();){
            vector<int> chosen(2);
            if(newInterval[0]!=-1 and newInterval[0]<=intervals[i][0]){
                chosen[0]=newInterval[0];
                chosen[1]=newInterval[1];
                newInterval[0]=-1;
            }else{
                chosen = intervals[i];
                i++;
            }
            if(ans.empty()||chosen[0]>ans.back()[1]){
                ans.push_back(chosen);
            }else{
                ans.back()[1]=max(ans.back()[1],chosen[1]);
            }
        }
        if(newInterval[0]!=-1){
            if(newInterval[0]>ans.back()[1])ans.push_back(newInterval);
            else ans.back()[1]=max(ans.back()[1],newInterval[1]);
        }
        return ans;
    }
};