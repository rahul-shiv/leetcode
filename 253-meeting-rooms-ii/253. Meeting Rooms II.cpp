class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ans = 0, n = intervals.size();
        vector<int> s(n),e(n);
        for(int i = 0; i < n; i++){
            s[i] = intervals[i][0];
            e[i] = intervals[i][1];
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        int i = 0, j = 0;
        while(i<n){
            while(i<n and s[i]<e[j])i++;
            ans=max(ans,i-j);
            while(i<n and s[i]>=e[j])j++;
        }
        return ans;
    }
};