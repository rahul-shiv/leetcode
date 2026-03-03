class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ans = 0, n = intervals.size();
        map<int,int> m;
        int l = INT_MAX, r = 0;
        for(int i = 0; i < n; i++){
            m[intervals[i][0]]+=1;
            m[intervals[i][1]]-=1;
        }
        int curr = 0;
        for(auto x:m){
            curr+=x.second;
            ans = max(curr,ans);
        }
        return ans;
    }
};