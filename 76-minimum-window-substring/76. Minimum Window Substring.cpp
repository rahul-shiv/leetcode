class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tv(128),sv(128);
        int n = s.length(), count=0;
        for(auto c:t){
            if(!tv[c-'A'])count++;
            tv[c-'A']+=1;
        }
        int l=0,r=0,minl=INT_MAX,start=-1;
        while(r<n){
            while(r<n and count){
                sv[s[r]-'A']++;
                if(tv[s[r]-'A'] and tv[s[r]-'A']==sv[s[r]-'A']) count--;
                r++;
            }
            while(l<r and count==0){
                if(r-l<minl){
                    minl=r-l;
                    start=l;
                }
                sv[s[l]-'A']--;
                if(tv[s[l]-'A'] and tv[s[l]-'A']>sv[s[l]-'A']) count++;
                l++;
            }
        }
        return minl==INT_MAX?"":s.substr(start,minl);
    }
};
