class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(256,-1);
        int ans = 0;
        int val = -1;
        for(int i = 0; i < s.length(); i++){
            val = max(v[s[i]],val);
            ans = max(ans,i-val);;
            v[s[i]]=i;
        }
        return ans;
    }
};