class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans(amount+1,2e4);
        ans[0]=0;
        sort(coins.begin(),coins.end());
        for(auto coin:coins){
            for(int i = coin; i<=amount;i++){
                ans[i] = min(ans[i],ans[i-coin]+1);
            }
        }
        return ans[amount]==2e4?-1:ans[amount];
    }
};