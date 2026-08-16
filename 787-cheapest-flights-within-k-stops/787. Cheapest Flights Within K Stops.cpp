class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto flight:flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        queue<tuple<int,int,int>> q;
        vector<int> dist(n,INT_MAX);
        q.push({src,0,0});
        dist[src] = 0;
        int u,l,d;
        while(!q.empty()){
            tie(u,l,d) = q.front();
            q.pop();
            if(l<=k){
                for(auto v:adj[u]){
                    if(d+v.second<dist[v.first]){
                        dist[v.first] = d+v.second;
                        q.push({v.first,l+1,dist[v.first]});
                    }
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};