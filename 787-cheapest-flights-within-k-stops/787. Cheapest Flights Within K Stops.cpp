class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int ans = INT_MAX;
        queue<vector<int>> q;
        vector<int> vis(n,INT_MAX);
        int u,l,cost;
        vector<vector<pair<int,int>>> g(n);
        for(auto f:flights){
            g[f[0]].push_back({f[1],f[2]});
        }
        q.push({src,0,0});
        while(!q.empty()){
            u = q.front()[0];
            l = q.front()[1];
            cost = q.front()[2];
            q.pop();
            if(u==dst) ans = min(ans,cost);
            for(auto v:g[u]){
                if(l==k+1) break;
                if(vis[v.first]>cost+v.second){
                    vis[v.first]=cost+v.second;
                    q.push({v.first,l+1,cost+v.second});
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};

// 0->1  1
// 0->2 5
// 1 ->2 1
// 2-> 3 1