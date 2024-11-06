class Solution {
public:
    vector<string> generateParenthesis(int n) {
        unordered_map<int,unordered_set<string>> ans;
        ans[0].insert("");
        for(int i = 1;i<=n;i++){
            for(int j = 0, k=i-j-1; j<n; j++,k--){
                for(auto &s1:ans[j]){
                    for(auto &s2:ans[k]){
                        ans[i].insert("()"+s1+s2);
                        ans[i].insert(s1+s2+"()");
                        ans[i].insert("("+s1+")"+s2);
                    }
                }
            }
        }
        return vector<string> (ans[n].begin(),ans[n].end());
    }
};