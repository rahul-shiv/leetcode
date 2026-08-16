class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n);
        vector<vector<int>> g(n);
        queue<int> q;
        for(auto p:prerequisites){
            indegree[p[0]]++;
            g[p[1]].push_back(p[0]);
        }
        for(int i = 0; i< n; i++){
            if(!indegree[i])q.push(i);
        }
        while(!q.empty()){
            n--;
            auto u = q.front();
            q.pop();
            for(auto v:g[u]){
                indegree[v]--;
                if(!indegree[v])q.push(v);
            }
        }
        return n==0;
    }
};