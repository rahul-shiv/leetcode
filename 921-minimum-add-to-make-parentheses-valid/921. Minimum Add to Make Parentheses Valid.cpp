class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans =0, o=0;
        for(auto c:s){
            if(c=='('){
                o++;
            }else{
                if(o)o--;
                else ans++;
            }
        }

        return ans+o;
    }
};