class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        stack<int> s;
        int n = temps.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            while(!s.empty() and temps[s.top()]<temps[i]){
                ans[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};