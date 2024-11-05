class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        st.push(-1);
        for(int i = 0; i < s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }else if(st.size()>1){
                st.pop();
                ans = max(ans,i-st.top());
            }else{
                st.top()=i;
            }
        }
        return ans;
    }
};