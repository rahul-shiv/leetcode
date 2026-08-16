class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        sort(coins.begin(),coins.end());
        vector<int> ans(amt+1,1e4+1);
        ans[0]=0;
        for(int i = coins[0];i<=amt;i++){
            for(auto coin:coins){
                if(coin>i)continue;
                ans[i]=min(ans[i],ans[i-coin]+1);
            }
        }
        return ans[amt]==1e4+1?-1:ans[amt];
    }
};