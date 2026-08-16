class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(!amount)return 0;
        sort(coins.begin(),coins.end());
        vector<int> dp(amount+1);
        queue<int> q;
        q.push(0);
        int u,v;
        while(!q.empty()){
            u = q.front();
            q.pop();
            for(auto coin:coins){
                v = u+coin;
                if(v==amount) return dp[u]+1;
                if(v<amount and !dp[v]){
                    dp[v]=dp[u]+1;
                    q.push(v);
                }
            }
        }
        return -1;
    }
};