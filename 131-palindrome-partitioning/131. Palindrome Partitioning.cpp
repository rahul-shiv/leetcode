class Solution {
    vector<vector<string>> ans;
    map<pair<int,int>,bool> p;
    bool isPalindrome(string &s, int i, int j){
        auto it = p.find({i,j});
        if(it!=p.end()){
            return it->second;
        }
        int x = i,y = j;
        while(i<j){
            if(s[i]!=s[j]){
                p[{x,y}]=false;
                return false;
            }
            i++;
            j--;
        }
        p[{x,y}]=true;
        return true;
    }

    void solve(string &s, int i, vector<string> &v){
        if(i==s.length()){
            ans.push_back(v);
            return;
        }
        for(int j = i;j<s.length();j++){
            if(isPalindrome(s,i,j)){
                v.push_back(s.substr(i,j-i+1));
                solve(s,j+1,v);
                v.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> v;
        solve(s,0,v);
        return ans;
    }
};