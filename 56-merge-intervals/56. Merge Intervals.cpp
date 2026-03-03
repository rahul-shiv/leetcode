class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),[](const auto l,const auto r){
            return l[0]==r[0]?l[1]<r[1]:l[0]<r[0];
        });
        for(auto interval:intervals){
            if(ans.size()){
                if(ans.back()[1]<interval[0]){
                    ans.push_back(interval);
                }else{
                    ans.back()[1]=max(interval[1],ans.back()[1]);
                }
            }else{
                ans.push_back(interval);
            }
        }
        return ans;
    }
};