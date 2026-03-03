class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> s(n),e(n);
        for(int i = 0; i < n; i++){
            s[i] = intervals[i][0];
            e[i] = intervals[i][1];
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        int ans = 0, l =0;
        for(int r = 0; r < n; r++){
            while(l<n and s[l]<e[r])l++;
            ans = max(ans,l-r);
        }
        return ans;
    }
};