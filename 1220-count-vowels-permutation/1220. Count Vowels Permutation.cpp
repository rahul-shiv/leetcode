class Solution {
public:
    int countVowelPermutation(int n) {
        #define MOD (1000000007)
        #define MODADD(x,y) x = ((x%MOD) + (y%MOD))%MOD
        vector<vector<int>> dp(n,vector<int>(5));
        for(int j = 0;j<5;j++)dp[0][j]=1;
        for(auto i = 0;i<n-1;i++){
            // a rule
            MODADD(dp[i+1][0],dp[i][1]);
            MODADD(dp[i+1][0],dp[i][2]);
            MODADD(dp[i+1][0],dp[i][4]);
            // e rule
            MODADD(dp[i+1][1],dp[i][0]);
            MODADD(dp[i+1][1],dp[i][2]);
            // i rule
            MODADD(dp[i+1][2],dp[i][1]);
            MODADD(dp[i+1][2],dp[i][3]);
            // o rule
            MODADD(dp[i+1][3],dp[i][2]);
            //u rule
            MODADD(dp[i+1][4],dp[i][2]);
            MODADD(dp[i+1][4],dp[i][3]);
        }
        int ans = 0;
        for(auto x:dp.back()){
            MODADD(ans,x);
        }
        return ans;
    }
};