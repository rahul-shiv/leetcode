class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>lh(n),rh(n);
        lh[0]=height[0];
        rh[n-1]=height[n-1];
        for(int i = 1; i<n;i++){
            lh[i]=max(lh[i-1],height[i]);
            rh[n-i-1]=max(rh[n-i],height[n-i-1]);
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans += min(lh[i],rh[i])-height[i];
        }
        return ans;
    }
    // redo with stack
};