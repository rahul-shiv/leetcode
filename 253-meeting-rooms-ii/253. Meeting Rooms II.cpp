class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size(), ans = 0;
        vector<int> s,e;
        for(auto x:intervals){
            s.push_back(x[0]);
            e.push_back(x[1]);
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        int i=0,j=0;
        while(i<n){
            while(i<n and s[i]<e[j]){
                i++;
            }
            ans = max(ans,i-j);
            j++;
        }
        ans = max(ans,i-j);
        return ans;
    }
};