class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector<int> ans(n);
        stack<int> s;
        for(int i = 0; i < n; i++){
            while(!s.empty() and temps[i]>temps[s.top()]){
                ans[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};