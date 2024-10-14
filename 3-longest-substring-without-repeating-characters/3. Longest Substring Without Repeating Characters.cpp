class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int ans = 0, start = -1;
        for(int i = 0; i < s.length(); i++){
            auto it = m.find(s[i]);
            if(it==m.end()){
                m[s[i]]=i;
            }else{
                start = max(start,m[s[i]]);
                m[s[i]] = i;
            }
            ans = max(ans,i-start);
        }
        return ans;
    }
};