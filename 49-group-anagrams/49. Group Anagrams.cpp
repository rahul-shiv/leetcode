class Solution {
    vector<int> to_vec(string &s){
        vector<int> vec(26);
        for(auto c:s){
            vec[c-'a']++;
        }
        return vec;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> m;
        for(auto str:strs){
           m[to_vec(str)].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto &x:m){
            ans.emplace_back(vector<string>(x.second.begin(),x.second.end()));
        }
        return ans;
    }
};