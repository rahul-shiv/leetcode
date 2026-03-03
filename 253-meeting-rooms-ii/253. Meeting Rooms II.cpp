class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ans = 0, n = intervals.size();
        int arr[(unsigned long)1e6+2]={0};
        for(int i = 0; i < n; i++){
            arr[intervals[i][0]]+=1;
            arr[intervals[i][1]]-=1;
        }
        int curr = 0;
        for(int i = 0; i < 1e6+2; i++){
            curr+=arr[i];
            ans = max(curr,ans);
        }
        return ans;
    }
};