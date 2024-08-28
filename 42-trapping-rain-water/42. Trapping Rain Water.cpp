class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n),rmax(n);
        lmax[0] = height[0];
        rmax[n-1] = height[n-1];
        for(int i = 1; i < n; i++){
            lmax[i] = max(height[i],lmax[i-1]);
            rmax[n-i-1] = max(height[n-i-1],rmax[n-i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += min(lmax[i],rmax[i])-height[i];
        }
        return ans;
    }
};