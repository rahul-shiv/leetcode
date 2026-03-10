class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, ans =0, lh =0, rh=0, t;
        while(l<=r){
            if (lh<rh){
                ans += max(0, min(lh,rh)-height[l]);
                lh = max(lh,height[l]);
                l++;
            }else{
                ans += max(0, min(lh,rh)-height[r]);
                rh = max(rh,height[r]);
                r--;
            }
        }
        return ans;
    }
};