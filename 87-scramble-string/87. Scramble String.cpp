class Solution {
   unordered_map<string, bool> memo;
    
    bool solve(const string &s1, const string &s2) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;

        string key = s1 + "," + s2;
        if (memo.find(key) != memo.end()) return memo[key];

        int n = s1.length();
        vector<int> c1(26), c2(26);

        for (int i = 0; i < n; i++) {
            c1[s1[i] - 'a']++;
            c2[s2[i] - 'a']++;
        }
        if (c1 != c2) return memo[key] = false;

        for (int i = 1; i < n; i++) {
            if (solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }
            if (solve(s1.substr(0, i), s2.substr(n - i)) && solve(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }
        return memo[key] = false;
    }

public:
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};