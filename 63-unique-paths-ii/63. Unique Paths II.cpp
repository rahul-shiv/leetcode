class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<int> dp(n);
        dp[0]=!g[0][0];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j]){
                    dp[j]=0;
                }
                else if(j){
                    dp[j] += dp[j-1];
                }
            }
        }
        return dp.back();
    }
};