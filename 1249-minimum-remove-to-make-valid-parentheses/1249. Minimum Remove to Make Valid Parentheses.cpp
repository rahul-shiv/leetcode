class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans,ans2;
        int cnt=0;
        for(int i = 0;i<s.length();i++){
            if(s[i]=='('){
                cnt++;
                ans+=s[i];
            }else if(s[i]==')'){
                if(cnt){
                    cnt--;
                    ans+=s[i];
                }
            }else{
                ans+=s[i];
            }
        }
        cnt = 0;
        for(int i = ans.length()-1;i>=0;i--){
            if(ans[i]=='('){
                if(cnt){
                    cnt--;
                    ans2+=ans[i];
                }
            }else if(ans[i]==')'){
                cnt++;
                ans2+=ans[i];
            }else{
                ans2+=ans[i];
            }
        }
        reverse(ans2.begin(),ans2.end());
        return ans2;
    }
};