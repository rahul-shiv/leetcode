class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt = 0;
        string tmp, ans;
        for(auto c:s){
            if(c==')'){
                if(cnt){
                    cnt--;
                    tmp+=c;
                }
            }else{
                if(c=='(')cnt++;
                tmp+=c;
            }
        }
        cnt=0;
        reverse(tmp.begin(),tmp.end());
        for(auto c:tmp){
            if(c=='('){
                if(cnt){
                    cnt--;
                    ans+=c;
                }
            }else{
                if(c==')')cnt++;
                ans+=c;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};