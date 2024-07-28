class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)return 0;
        unordered_map<int,vector<int>> g;
        vector<bool> vis(routes.size());
        for(int i = 0; i < routes.size();i++){
            for(auto u:routes[i]){
                g[u].push_back(i);
            }
        }
        queue<pair<int,int>> q;
        q.push({source,0});
        int u,d;
        while(!q.empty()){
            tie(u,d)=q.front();
            q.pop();
            for(auto route:g[u]){
                if(vis[route])continue;
                vis[route]=true;
                for(auto v:routes[route]){
                    if(v==target)return d+1;
                    q.push({v,d+1});
                }
            }
        }
        return -1;
    }
};