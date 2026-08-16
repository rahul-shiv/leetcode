class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        vector<bool> vis(amt+1, false);
        sort(coins.begin(),coins.end());
        queue<pair<int,int>> q;
        q.push({0,0});
        int u,l;
        while(!q.empty()){
            tie(u,l)=q.front();
            if(u==amt)return l;
            q.pop();
            for(auto coin:coins){
                if((long)u+coin<=amt and !vis[u+coin]){
                    q.push({u+coin,l+1});
                    vis[u+coin]=true;
                }
            }
        }
        return -1;
    }
};