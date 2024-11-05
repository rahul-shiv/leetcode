class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0, n = s.length();
        stack<int> st;
        st.push(-1);
        for(int i = 0;i<n;i++){
            if(s[i]==')'){
                if(st.size()==1){
                    ans = max(ans,i-1-st.top());
                    st.top()=i;
                }else{
                    st.pop();
                    ans = max(ans,i-st.top());
                }
            }else{
                st.push(i);
            }
        }

        return ans;
    }
};