class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int> m;
        int l = 0, r = 0, n = s.length();
        int ans = -1;
        string s2;
        while(l<n){
            while(r<n-1 and s[r]==s[r+1]){
                r++;
            }
            if(r-l+1>=3){
                m[s.substr(l,r-l-1)]+=3;
                ans = max(r-l-1, ans);
            }
            if(r-l+1>=2){
                s2 = s.substr(l,r-l);
                m[s2]+=2;
                if(m[s2]>=3)ans = max(r-l, ans);
            }
            if(r-l+1>=1){
                s2 = s.substr(l,r-l+1);
                m[s2]+=1;
                if(m[s2]>=3)ans = max(r-l+1, ans);
            }
            l = r+1;
            r++;
        }
        return ans;
    }
};