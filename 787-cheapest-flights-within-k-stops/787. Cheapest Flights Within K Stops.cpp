class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjs(n);
        vector<int> mins(n,INT_MAX);
        mins[src]=0;
        for(auto flight:flights){
            adjs[flight[0]].push_back({flight[1],flight[2]});
        }
        queue<tuple<int,int,int>> q;
        q.push(make_tuple(src,k,0));
        int x,hop,nextx,nextp,w,nw;
        while(!q.empty()){
            tie(x,hop,w) = q.front();
            q.pop();
            for(auto adj:adjs[x]){
                nextx = adj.first;
                nw = w + adj.second;
                if(hop>=0 and nw<mins[nextx]){
                    mins[nextx]=nw;
                    q.push({nextx,hop-1,nw});
                }
            }
        }
        return mins[dst]==INT_MAX?-1:mins[dst];
    }
};