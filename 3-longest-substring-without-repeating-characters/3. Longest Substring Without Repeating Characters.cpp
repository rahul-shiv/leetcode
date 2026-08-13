class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int ans = 0, prev = -1;
        for(int i = 0; i < s.length(); i++){
            auto it = m.find(s[i]);
            if(it==m.end() or it->second<=prev){
                ans = max(ans,i-prev);
            }else{
                prev = m[s[i]];
            }
            m[s[i]]=i;
        }
        return ans;
    }
};