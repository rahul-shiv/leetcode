class Solution {
    vector<vector<int>> g,ans;
    vector<int> tin,low;
    int timer;
public:
    void solve(int v, int p){
        tin[v]=low[v]=timer++;
        for(auto to:g[v]){
            if(to==p)continue;
            if(tin[to]!=-1){
                low[v]=min(low[v],low[to]);
            }else{
                solve(to,v);
                low[v]=min(low[v],low[to]);
                if(low[to]>tin[v])ans.push_back({v,to});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        g.resize(n);
        tin.resize(n,-1);
        low.resize(n,-1);
        timer = 0;
        for(auto c:connections){
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }
        solve(0,-1);
        return ans;
        
    }
};