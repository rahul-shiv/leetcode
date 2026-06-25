class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        vector<vector<int>> g(n);
        for(auto edge:edges){
            indegree[edge[0]]++;
            indegree[edge[1]]++;
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        queue<pair<int,int>> q;
        vector<int> ans;
        int currlevel = 0;
        for (int i = 0; i<n; i++){
            if(indegree[i]==1)q.push(make_pair(i,0));
        }
        if(q.size()==0)return {0};
        int node, level;
        while(!q.empty()){
            tie(node,level) = q.front();
            q.pop();
            if(level>currlevel){
                ans={};
                currlevel=level;
            }
            ans.push_back(node);
            for(auto next:g[node]){
                indegree[next]--;
                if(indegree[next]==1){
                    q.push(make_pair(next,level+1));
                }
            }

        }
        return ans;
    }
};