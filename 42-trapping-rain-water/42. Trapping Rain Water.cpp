class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> pos;
        int ans = 0;
        for(int i = 0; i < height.size(); i++){
            while(!pos.empty() and height[i]>height[pos.top()]){
                int x = height[pos.top()];
                pos.pop();
                if(!pos.empty())ans+=(min(height[pos.top()],height[i])-x)*(i-pos.top()-1);
            }
            pos.push(i);
        }
        return ans;
    }
};