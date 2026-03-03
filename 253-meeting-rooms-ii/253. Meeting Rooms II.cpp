class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size(), ans = 0;
        vector<pair<int,int>> v;
        for(auto x:intervals){
            v.push_back({x[0],1});
            v.push_back({x[1],0});
        }
        sort(v.begin(),v.end());
        int curr = 0;
        for(auto &x:v){
            if(x.second){
                curr++;
                ans=max(curr,ans);
            }else{
                curr--;
            }
        }
        return ans;
    }
};