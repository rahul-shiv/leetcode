class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int t = 0;
        string temp="", ans="";
        for(auto c:s){
            if(c=='('){
                t+=1;
                temp+=c;
            }else if(c==')'){
                if(t){
                    temp+=c;
                    t-=1;
                }
            }else{
                temp+=c;
            }
        }
        t=0;
        reverse(temp.begin(),temp.end());
        for(auto c:temp){
            if(c==')'){
                t+=1;
                ans+=c;
            }else if(c=='('){
                if(t){
                    ans+=c;
                    t-=1;
                }
            }else{
                ans+=c;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};