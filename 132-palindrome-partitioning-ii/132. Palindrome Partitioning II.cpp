class Solution {
    bool isPalindrome(string &s, int i, int j){
        int x = i,y = j;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> ans(n+1);
        for(int i = 0;i<n+1;i++)ans[i]=i-1;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                if(ans[j+1]>ans[i]+1 and isPalindrome(s,i,j)){
                    ans[j+1]=min(ans[j+1],ans[i]+1);
                }
            }
        }
        return ans[n];
    }
};