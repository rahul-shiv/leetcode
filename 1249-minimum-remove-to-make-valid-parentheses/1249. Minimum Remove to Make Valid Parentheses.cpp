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
        for(int i = tmp.length()-1; i >= 0; i--){
            if(tmp[i]=='('){
                if(cnt){
                    cnt--;
                    ans+=tmp[i];
                }
            }else{
                if(tmp[i]==')')cnt++;
                ans+=tmp[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};