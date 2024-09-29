class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i = 2;i<=n;i++){
            for(int l=0,r=i-l-1;l<=r;l++,r--){
                dp[i]+=(1+(l!=r))*dp[l]*dp[r];
            }
        }
        return dp[n];
    }
};