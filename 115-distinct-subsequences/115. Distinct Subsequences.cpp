class Solution {
public:
    int numDistinct(string s, string t) {
        unordered_map<char,vector<int>> m;
        for(int i = 0; i < t.length();i++){
            m[t[i]].push_back(i);
        }
        vector<uint64_t> dp(t.length());
        for(auto c:s){
            auto it = m.find(c);
            if(it==m.end())continue;
            for(auto it2=it->second.rbegin();it2!=it->second.rend();it2++){
                if(*it2){
                    dp[*it2]+=dp[*it2-1];
                }else{
                    dp[*it2]+=1;
                }
            }
        }
        return dp.back();
    }
};