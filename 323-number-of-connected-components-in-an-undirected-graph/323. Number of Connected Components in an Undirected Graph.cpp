class Solution {
    vector<bool> vis;
    vector<vector<int>> g;
    void dfs(int u){
        vis[u]=true;
        for(auto v:g[u]){
            if(!vis[v]){
                dfs(v);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vis = vector<bool>(n);
        g = vector<vector<int>>(n);
        for(auto edge:edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i);
                ans++;
            }
        }
        return ans;
    }
};