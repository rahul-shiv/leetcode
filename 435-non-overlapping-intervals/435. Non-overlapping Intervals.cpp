class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto &a, const auto &b){
            return a[1]==b[1]?a[0]>b[0]:a[1]<b[1];
        });
        int ans = 0, prev = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0]<prev){
                ans++;
            }else{
                prev = intervals[i][1];
            }
        }
        return ans;
    }
};