class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1);
        dp[0]=1;
        for(int i = 0; i < n; i++){
            if(dp[i]){
                for(auto word:wordDict){
                    if(word == s.substr(i,word.length())){
                        dp[i+word.length()] = true;
                    }
                }
            }
        }
        return dp[n];
    }
};