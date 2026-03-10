class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1, ans = min(height[0],height[n-1])*(n-1);
        while(i<j){
            if(height[i]>height[j]){
                ans = max(ans,height[j]*(j-i));
                j--;
            }else{
                ans = max(ans,height[i]*(j-i));
                i++;
            }
        }
        return ans;
    }
};