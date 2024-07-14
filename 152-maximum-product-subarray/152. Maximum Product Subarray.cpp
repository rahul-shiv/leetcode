class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double ma=nums[0],mi=nums[0];
        double ans = ma;
        for(int i=1; i<nums.size();i++){
            if(!nums[i]){
                ma=mi=nums[i];
            }else{
                double x = ma,y=mi;
                ma = max((double)nums[i],max(y*nums[i],x*nums[i]));
                mi = min((double)nums[i],min(y*nums[i],x*nums[i]));
            }
            ans = max(ans,ma);
        }
        return ans;
    }
};