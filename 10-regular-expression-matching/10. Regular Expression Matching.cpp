class Solution {
    vector<vector<int>> vis;
    int m,n;
    bool solve(string s, string p){
        if(s.length()==0 and p.length()==0)return true;
        if(p.length()==0)return false;
        if(vis[s.length()][p.length()])return vis[s.length()][p.length()]-1;
        bool t = false;
        if(p.size()>1 and p[1]=='*'){
            t = max(t,solve(s,p.substr(2)));
            if(!s.empty() and (s[0]==p[0] or p[0]=='.')) {
                if(!t)t = max(t,solve(s.substr(1),p));
            }
        }else if(!s.empty() and (s[0]==p[0] or p[0]=='.')){
            t = max(t,solve(s.substr(1),p.substr(1)));
        }
        vis[s.length()][p.length()] = t+1;
        return t;
    }
public:
    bool isMatch(string s, string p) {
        m = s.length();
        n = p.length();
        vis = vector<vector<int>>(m+1,vector<int>(n+1));
        return solve(s,p);
    }
};