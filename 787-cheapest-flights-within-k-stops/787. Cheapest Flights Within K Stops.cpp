class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> ans(n,{INT_MAX,INT_MAX});
        vector<vector<pair<int,int>>> g(n);
        for(auto flight:flights){
            g[flight[0]].push_back({flight[1],flight[2]});
        }
        priority_queue<tuple<int,int,int>> pq;
        ans[src]={0,0};
        pq.push({0,-1,src});
        int u,hops,dist,v,vdist;
        while(!pq.empty()){
            tie(dist,hops,u)=pq.top();
            pq.pop();
            for(auto &vinfo:g[u]){
                tie(v,vdist)=vinfo;
                if(hops+1<=k and (hops+1<ans[v].second or dist+vdist<ans[v].first)){
                    ans[v].first=min(dist+vdist,ans[v].first);
                    ans[v].second=min(hops+1,ans[v].second);
                    pq.push({dist+vdist,hops+1,v});
                }
            }
        }
        return ans[dst].first==INT_MAX?-1:ans[dst].first;
    }
};