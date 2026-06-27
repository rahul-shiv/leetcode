class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto &a, const auto &b){
            return a[1]==b[1]?a[0]<b[0]:a[1]<b[1];
        });
        int n = intervals.size();
        vector<vector<int>> sol;
        for(int i = 0; i < n; i++){
            if(sol.empty() or intervals[i][0]>=sol.back()[1]){
                sol.push_back(intervals[i]);
            }else if(intervals[i][1]<sol.back()[1]){
                sol.back()=intervals[i];
            }
        }
        return n-sol.size();
    }
};