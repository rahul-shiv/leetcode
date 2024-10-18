class Solution {
    string shift(string s){
        int d = s[0]-'a';
        for(int i = 0;i<s.length();i++){
            s[i]-=d;
            if(s[i]<'a'){
                s[i]+=26;
            }
        }
        return s;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>> m;
        for(auto s:strings){
            string t = shift(s);
            m[t].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto x:m){
            ans.push_back(move(x.second));
        }
        return ans;
    }
};