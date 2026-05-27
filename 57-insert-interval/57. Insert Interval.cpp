class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n==0){
            return {newInterval};
        }
        vector<vector<int>> ans;
        vector<int> ins;
        for(int i = 0; i <intervals.size(); i++){
            if(newInterval[0]==-1 or intervals[i][0]<=newInterval[0]){
                ins = intervals[i];
            }else{
                ins = newInterval;
                newInterval[0]=-1;
                i--;
            }
            if(ans.empty()||ins[0]>ans.back()[1]){
                ans.push_back(ins);
            }else{
                ans.back()[1]=max(ans.back()[1],ins[1]);
            }
        }
        if(newInterval[0]!=-1){
            if(newInterval[0]>ans.back()[1]){
                ans.push_back(newInterval);
            }else{
                ans.back()[1]=max(ans.back()[1],newInterval[1]);
            }
        }
        return ans;
    }
};