class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans, indegree(n);
        vector<vector<int>> g(n);
        for(auto edge:edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }
        queue<pair<int,int>> q;
        int l = 0;
        int u,cl;
        for(int i = 0; i < n; i++){
            if(indegree[i]==1||indegree[i]==0){
                q.push({i,0});
                indegree[i]--;
            }
        }
        while(!q.empty()){
            tie(u,cl) = q.front();
            q.pop();
            if(cl==l){
                ans.push_back(u);
            }else{
                l=cl;
                ans = vector<int>();
                ans.push_back(u);
            }
            for(auto v:g[u]){
                indegree[v]--;
                if(indegree[v]==1){
                    q.push({v,cl+1});
                }
            }
        }
        return ans;
    }
};