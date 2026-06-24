class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> v;
        for(int i = 0; i < n; i++){
            v.emplace_back(vector<int>({endTime[i], startTime[i], profit[i]}));
        }
        sort(v.begin(),v.end());
        map<int,int> ans;
        ans[0]=0;
        int ret =0 ;

        for(int i = 0; i < n; i++){
            auto it = ans.upper_bound(v[i][0]);
            it--;
            auto it2 = ans.upper_bound(v[i][1]);
            it2--;
            ans[v[i][0]] = max(it->second, it2->second+v[i][2]);
            ret = max(ret, ans[v[i][0]]);
        }
        return ret;
    }
};