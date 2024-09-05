class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length())return false;
        vector<bool> dp(s2.length()+1);
        for(int i = 0; i <= s1.length(); i++){
            for(int j = 0; j <= s2.length(); j++){
                if(i==0 and j==0){
                    dp[j]=true;
                }else if(i and j){
                    dp[j] = (dp[j-1] and s2[j-1]==s3[i+j-1]) || (dp[j] and s1[i-1]==s3[i+j-1]);
                }else if(i){
                    dp[j] = (dp[j] and s1[i-1]==s3[i+j-1]);
                }else{
                    dp[j] = (dp[j-1] and s2[j-1]==s3[i+j-1]);
                }
            }
        }
        return dp.back();
    }
};