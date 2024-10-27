class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<pair<int,int>> e(n);
        for(int i = 0;i<n;i++){
            e[i].first=endTime[i];
            e[i].second=i;
        }
        sort(e.begin(),e.end());
        map<int,int> m;
        m[0]=0;
        int i;
        for(auto &end:e){
            i = end.second;
            auto it = prev(m.upper_bound(startTime[i]));
            m[end.first]=max(m[end.first],it->second+profit[i]);
            it = m.find(end.first);
            auto it2= prev(it);
            it->second = max(it->second,it2->second);
        }
        return m.rbegin()->second;
    }
};