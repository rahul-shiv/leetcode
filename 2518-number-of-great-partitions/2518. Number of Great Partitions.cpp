class Solution {
    #define MOD (1000000007)
public:
    int countPartitions(vector<int>& nums, int k) {
        vector<int64_t> ans(k);
        ans[0]=1;
        int64_t tot = 1,s=0;
        for(int i = 0;i<nums.size();i++){
            for(int j = k-1;j-nums[i]>=0;j--){
                if(ans[j-nums[i]]){
                    ans[j]=(ans[j]%MOD+ans[j-nums[i]]%MOD)%MOD;
                }
            }
            tot=(tot*2)%MOD;
            s = (s + nums[i]%MOD)%MOD;
        }
        if(s<2*k)return 0;
        int64_t t = 0;
        for(int i = 0;i<k;i++){
            t = (t%MOD+ans[i]%MOD)%MOD;
        }
        t = (t*2)%MOD;
        // cout<<tot<<" "<<t;z
        return (tot-t+MOD)%MOD;
    }
};