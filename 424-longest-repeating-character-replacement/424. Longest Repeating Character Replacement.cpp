class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, n = s.length(),ans = 0,m=0;
        vector<int> c(26);
        while(r<n){
            ans = max(ans,r-l);
            c[s[r]-'A']+=1;
            m = max(m,c[s[r]-'A']);
            r+=1;
            if(r-l-m>k){
                c[s[l]-'A']-=1;
                l+=1;
            }
        }
        ans = max(ans,r-l);
        return ans;
    }
};