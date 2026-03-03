class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto const &a, auto const &b){
            return a[0]==b[0]?a[1]<b[1]:a[0]<b[0];
        });
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int i = 1;
        for(;i<intervals.size();i++){
            if(intervals[i][0]<=ans.back()[1]){
                ans.back()[1]=max(intervals[i][1],ans.back()[1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};