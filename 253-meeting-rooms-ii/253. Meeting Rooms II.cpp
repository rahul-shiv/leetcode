class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ans = 0, n = intervals.size();
        int arr[(unsigned long)1e6+2]={0};
        int l = INT_MAX, r = 0;
        for(int i = 0; i < n; i++){
            l = min(l,intervals[i][0]);
            r = max(r,intervals[i][1]);
            arr[intervals[i][0]]+=1;
            arr[intervals[i][1]]-=1;
        }
        int curr = 0;
        for(int i = l; i < r+1; i++){
            curr+=arr[i];
            ans = max(curr,ans);
        }
        return ans;
    }
};