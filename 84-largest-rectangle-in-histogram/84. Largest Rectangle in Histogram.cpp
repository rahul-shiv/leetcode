class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int ans = 0,x,start;
        for(int i = 0;i<heights.size();i++){
            x=i;
            while(!s.empty() and heights[s.top()]>=heights[i]){
                x = s.top();
                s.pop();
                ans = max(ans,heights[x]*(i-x));
                heights[x]=heights[i];
            }
            s.push(x);
        }
        return ans;
    }
};