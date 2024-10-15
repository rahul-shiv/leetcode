class Solution {
    bool cmp(vector<int>&sv, vector<int>&tv){
        for(int i = 0; i < 128;i++){
            if(sv[i]<tv[i])return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        vector<int> tv(128),sv(128);
        int n = s.length();
        for(auto c:t){
            tv[c-'A']+=1;
        }
        int l=0,r=0,minl=INT_MAX,start=-1;
        while(r<n){
            while(r<n and !cmp(sv,tv)){
                sv[s[r]-'A']++;
                r++;
            }
            while(l<r and cmp(sv,tv)){
                if(r-l<minl){
                    minl=r-l;
                    start=l;
                }
                sv[s[l]-'A']--;
                l++;
            }
        }
        return minl==INT_MAX?"":s.substr(start,minl);
    }
};
