class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=1,n=s.size(), ans = 1,x=0;
        char currm = s[0];
        unordered_map<char,int> m;
        m[s[0]]+=1;
        while(r<n){
            m[s[r]]++;
            if(s[r]!=currm){
                x++;
                if(m[s[r]]>=m[currm]){
                    currm = s[r];
                    x = (r-l+1)-m[s[r]];
                }
            }
            while(x>k){
                m[s[l]]--;
                if(s[l]==currm){
                    int t = 0;
                    for(auto temp:m){
                        if(temp.second>t){
                            t=temp.second;
                            currm=temp.first;
                        }
                    }
                    x = (r-l)-m[currm];
                }else{
                    x--;
                }
                l++;
            }
            ans = max(r-l+1,ans);
            r++;
        }
        return ans;
    }
};