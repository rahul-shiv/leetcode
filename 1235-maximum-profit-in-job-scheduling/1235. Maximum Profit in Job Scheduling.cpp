class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> v;
        for(int i = 0; i < n; i++){
            v.emplace_back(vector<int>({endTime[i], startTime[i], profit[i]}));
        }
        sort(v.begin(),v.end());
        vector<pair<int,int>> m;
        m.push_back({0,0});
        int ret =0 ;

        for(int i = 0; i < n; i++){
            auto it = upper_bound(m.begin(),m.end(),make_pair(v[i][0],INT_MAX));
            it--;
            auto it2 = upper_bound(m.begin(),m.end(),make_pair(v[i][1],INT_MAX));
            it2--;
            if(it->first==v[i][0]){
                m.back().second = max(it->second, it2->second+v[i][2]);
            }else{
                m.push_back({v[i][0], max(it->second, it2->second+v[i][2])});
            }
            ret = max(ret, m.back().second);
        }
        return ret;
    }
};