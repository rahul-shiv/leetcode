class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        int p1 = 0,p2 = 0,t;
        for(auto num:nums){
            t = p1;
            p1 = max(p1,num+p2);
            p2 = t;
        }
        return max(p1,p2);
    }
};