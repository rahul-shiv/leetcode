class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)return 0;
        int i = 0;
        unordered_map<int,vector<int>> g;
        unordered_set<int> vis;
        for(auto &route:routes){
            for(auto x:route){
                g[x].push_back(i);
            }
            i++;
        }
        queue<pair<int,int>> q;
        int u,dep;
        q.push({source,0});
        while(!q.empty()){
            tie(u,dep)=q.front();
            q.pop();
            for(auto route:g[u]){
                auto it = vis.find(route);
                if(it!=vis.end())continue;
                vis.insert(route);
                for(auto v:routes[route]){
                    if(v==target)return dep+1;
                    q.push({v,dep+1});
                }
            }
        }
        return -1;
    }
};