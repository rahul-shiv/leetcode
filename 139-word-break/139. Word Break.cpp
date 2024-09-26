class Solution {
    unordered_set<string> words;
    vector<bool> vis;
    bool solve(string s, int i){
        if(i==s.length())return true;
        bool t = false;
        vis[i]=true;
        for(int j = 1;j<=s.length()-i;j++){
            string word = s.substr(i,j);
            auto it = words.find(word);
            if(it!=words.end() and !vis[i+j]){
                t = solve(s,i+j);
                if(t) break;
            }
        }
        return t;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        words = unordered_set<string>(wordDict.begin(),wordDict.end());
        vis = vector<bool>(s.size());
        return solve(s, 0);
    }
};