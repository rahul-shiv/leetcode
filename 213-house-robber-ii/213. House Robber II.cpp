class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size(),minus2=0,temp,minus1=nums[0];
        int ans;
        for(int i = 1; i<n-1; i++){
            temp=max(minus2+nums[i],minus1);
            minus2=minus1;
            minus1=temp;
        }
        ans = minus1;
        if(n>1){
            minus2=0,temp,minus1=nums[1];
            for(int i = 2; i<n; i++){
                temp=max(minus2+nums[i],minus1);
                minus2=minus1;
                minus1=temp;
            }        
        }
        return  max(ans,minus1);
    }
};