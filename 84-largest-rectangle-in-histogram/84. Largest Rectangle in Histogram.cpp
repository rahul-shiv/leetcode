class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int ans = 0;
        stack<int> s;
        for(int i = 0; i < heights.size(); i++){
            int x = i;
            while(!s.empty() and heights[s.top()]>=heights[i]){
                x = s.top();
                s.pop();
                ans = max(heights[x]*(i-x),ans);
                heights[x]=heights[i];
            }
            s.push(x);
        }
        return ans;
    }
};