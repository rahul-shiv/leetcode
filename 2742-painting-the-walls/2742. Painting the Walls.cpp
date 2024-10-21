class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<int> dp(time.size()+1,1e9);
        dp[0]=0;
        for(int i = 0;i<time.size();i++){
            for(int j = dp.size()-1;j>0;j--){
                dp[j]=min(dp[j],dp[max(j-time[i]-1,0)]+cost[i]);
            }
        }
        return dp.back();
    }
};
