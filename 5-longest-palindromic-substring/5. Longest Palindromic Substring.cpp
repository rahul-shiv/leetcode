class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i = 0; i<n;i++)dp[i][i]=1;
        string ans = s.substr(0,1);
        for(int l = 2; l<=n;l++){
            for(int i = 0;i<=n-l;i++){
                int j = i+l-1;
                if(s[i]==s[j]){
                    if(l==2){
                        dp[i][j]=2;
                    }else if(dp[i+1][j-1]){
                        dp[i][j]=dp[i+1][j-1]+2;
                    }
                    if(dp[i][j]>ans.length()){
                        ans = s.substr(i,l);
                    }
                }
            }
        }
        return ans;
    }
};