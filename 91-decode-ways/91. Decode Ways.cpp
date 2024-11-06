class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> ans(n+1);
        ans[0]=1;
        for(int i = 0;i<n;i++){
            bool flg = false;
            if(s[i]>'0'){
                ans[i+1]+=ans[i];
                flg = true;
            }
            if(i>0 and (s[i-1]=='1' or (s[i-1]=='2' and s[i]<'7'))){
                ans[i+1]+=ans[i-1];
                flg = true;
            }
            if(!flg)return 0;
        }
        return ans.back();
    }
};