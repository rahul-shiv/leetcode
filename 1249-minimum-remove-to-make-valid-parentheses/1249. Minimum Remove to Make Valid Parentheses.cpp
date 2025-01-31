class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt = 0;
        string mid,ans;
        for(int i = s.length()-1;i>=0 ;i--){
            if(s[i]==')'){
                cnt+=1;
                mid+=s[i];
            }else if(s[i]=='('){
                if(cnt){
                    cnt--;
                    mid+=s[i];
                }
            }else{
                mid+=s[i];
            }
        }
        cnt=0;
        for(int i = mid.length()-1;i>=0 ;i--){
            if(mid[i]=='('){
                cnt+=1;
                ans+=mid[i];
            }else if(mid[i]==')'){
                if(cnt){
                    cnt--;
                    ans+=mid[i];
                }
            }else{
                ans+=mid[i];
            }
        }
        return ans;
    }
};