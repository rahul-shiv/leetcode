class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& l, const vector<int>& r){
                return l[1]==r[1]?l[0]>r[0]:l[1]<r[1];
        });
        vector<vector<int>> lis;
        int ans=0;
        for(auto &interval:intervals){
            if(!lis.empty() and lis.back()[1]>interval[0]){
                if(lis.back()[1]>interval[1])lis.back()=interval;
                ans++;
            }else{
                lis.emplace_back(interval);
            }
        }
        return ans;
    }
};