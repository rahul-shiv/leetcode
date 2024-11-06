class Solution {
public:
    vector<string> generateParenthesis(int n) {
        unordered_map<int,unordered_set<string>> ans;
        ans[0].insert("");
        for(int i = 1;i<=n;i++){
            for(auto &s:ans[i-1]){
                ans[i].insert("("+s+")");
                ans[i].insert("()"+s);
                ans[i].insert(s+"()");
            }
            for(int j = 2, k=i-j; j<n and k>=j; j++,k--){
                for(auto &s1:ans[j]){
                    for(auto &s2:ans[k]){
                        ans[i].insert(s1+s2);
                        ans[i].insert(s2+s1);
                    }
                }
            }
        }
        return vector<string> (ans[n].begin(),ans[n].end());
    }
};