class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> valid(n+1);
        valid[0]=true;
        for(int i = 0 ; i < n; i++){
            if(!valid[i])continue;
            for(auto &word:wordDict){
                int j = 0;
                for(;j<word.length();j++)if(s[i+j]!=word[j])break;
                if(j==word.length())valid[i+j]=true;
            }
        }
        return valid[n];
    }
};

//   l e e t c o d e
// 1 0 0 0 1 0 0 0 1
